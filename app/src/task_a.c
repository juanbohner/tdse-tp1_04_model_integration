/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : task_a.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"
#include "app.h"
#include "task_a_fsm.h"
#include "task_b_fsm.h"
#include "task_a_queue.h"

/********************** macros and definitions *******************************/
#define G_TASK_A_CNT_INI	0u

#define TASK_A_DEL_INI		0u
#define TASK_A_DEL_MAX		50u

/********************** internal data declaration ****************************/
s_task_a_t	state_task_a;
e_task_a_t	event_task_a;

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_task_a 		= "Task A (System Modeling)";

/********************** external data declaration *****************************/
uint32_t g_task_a_cnt;

/********************** external functions definition ************************/
void task_a_init(void *parameters)
{
	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_a_init), p_task_a);

	g_task_a_cnt = G_TASK_A_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_a_cnt), (int)g_task_a_cnt);

	state_task_a = STATE_TASK_A_0;
	event_task_a = EVENT_TASK_A_0;
	init_queue_event_task_a();

	/* Print out: Task execution FSM */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(state_task_a), (int)state_task_a);
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(event_task_a), (int)event_task_a);
}

void task_a_update(void *parameters)
{
	/* Update Task A Counter */
	g_task_a_cnt++;

	static uint32_t then_task_a = TASK_A_DEL_INI;
	static uint32_t now_task_a  = TASK_A_DEL_INI;

	now_task_a = HAL_GetTick();
	if ((now_task_a - then_task_a) >= TASK_A_DEL_MAX)
	{
		/* Reset then = now */
		then_task_a = now_task_a;
	}

	if (true == any_event_task_a())
	{
		state_task_a = get_event_task_a();
		switch (state_task_a)
		{
			case STATE_TASK_A_0:

				if (EVENT_TASK_A_1 == event_task_a){
					/* Get the event to excite Task B. */
					g_event_task_b= EVENT_TASK_B_1;
					g_b_event_task_b = true;

					//HAL_GPIO_WritePin(LED_A_PORT, LED_A_PIN, LED_ON);
					//HAL_GPIO_TogglePin(LED_A_PORT, LED_A_PIN);
					state_task_a =STATE_TASK_A_1;
				}
				break;

			case STATE_TASK_A_1:

				if (EVENT_TASK_A_0 == event_task_a){
					HAL_GPIO_WritePin(LED_A_PORT, LED_A_PIN, LED_OFF);
					/* Get the event to excite Task A. */
					g_event_task_b = EVENT_TASK_B_0;
					g_b_event_task_b = true;

					state_task_a =STATE_TASK_A_0;
				}
				break;

			case STATE_TASK_A_2:

				if (EVENT_TASK_A_0 == event_task_a)
					state_task_a =STATE_TASK_A_0;

				if (EVENT_TASK_A_1 == event_task_a)
					state_task_a =STATE_TASK_A_1;

			default:

				break;
		}
	}
}

/********************** end of file ******************************************/
