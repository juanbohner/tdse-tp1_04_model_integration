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
 * @file   : task_a_test.c
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
#include "task_a_queue.h"

/********************** macros and definitions *******************************/
#define G_TASK_A_TEST_CNT_INI	0u

#define TASK_A_TEST_CNT_INI		0u
#define TASK_A_TEST_CNT_MAX		100000u

#define TASK_A_TEST_DEL_INI		0u
#define TASK_A_TEST_DEL_MAX		5000u

//typedef enum {TEST_0, TEST_1, TEST_2} test_x_t;
#define TASK_A_TEST_0 (0)
#define TASK_A_TEST_1 (1)
#define TASK_A_TEST_2 (2)

#define TASK_A_TEST_X (TASK_A_TEST_0)

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_task_a_test	= "Task A (System Modeling) Test";

#if (TASK_A_TEST_X == TASK_A_TEST_0)
/* Array of events to excite Task A */
const e_task_a_t e_task_a_array[] = {EVENT_TASK_A_0, EVENT_TASK_A_1, EVENT_TASK_A_2, EVENT_TASK_A_0, EVENT_TASK_A_1, EVENT_TASK_A_2};
#endif

#if (TASK_A_TEST_X == TASK_A_TEST_1)
/* Array of events to excite Task A */
const e_task_a_t e_task_a_array[] = {EVENT_TASK_A_2 EVENT_TASK_A_1, EVENT_TASK_A_0, EVENT_TASK_A_2 EVENT_TASK_A_1, EVENT_TASK_A_0};
#endif

#if (TASK_A_TEST_X == TASK_A_TEST_2)
/* Array of events to excite Task A */
const e_task_a_t e_task_a_array[] = {EVENT_TASK_A_0, EVENT_TASK_A_1, Event_2, EVENT_TASK_A_2, EVENT_TASK_A_1, EVENT_TASK_A_0};
#endif

/********************** external data declaration *****************************/
uint32_t g_task_a_test_cnt;

/********************** external functions definition ************************/
void task_a_test_init(void *parameters)
{
	uint32_t i = TASK_A_TEST_X;

	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_a_test_init), p_task_a_test);

	g_task_a_test_cnt = G_TASK_A_TEST_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_a_test_cnt), (int)g_task_a_test_cnt);

	/* Print out: Array of events to excite Task A */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(e_task_a_array), (int)i);
}

void task_a_test_update(void *parameters)
{

	#if (TEST_X == TEST_0)

	static uint32_t task_a_test_cnt = TASK_A_TEST_CNT_INI;
	uint32_t i = TASK_A_TEST_X;

	static e_task_a_t event_task_a_test;

	static uint32_t then_task_a_test = TASK_A_TEST_DEL_INI;
	static uint32_t now_task_a_test  = TASK_A_TEST_DEL_INI;

	#endif

	#if (TEST_X == TEST_1)

	/* Here another code */

	#endif

	#if (TEST_X == TEST_2)

	/* Here Chatbot Artificial Intelligence generated code */

	#endif

	/* Update Task A Counter */
	g_task_a_test_cnt++;

	/* Check the current tick */
	now_task_a_test = HAL_GetTick();
	if ((now_task_a_test - then_task_a_test) >= TASK_A_TEST_DEL_MAX)
	{
		/* Only if the current tick is TASK_A_TEST_DEL_MAX mS after the last */
		/* Reset then = now */
		then_task_a_test = now_task_a_test;

		/* Print out: Application Update */
		LOGGER_LOG("  %s is is running - %s\r\n", GET_NAME(task_a_test_update), p_task_a_test);

		/* Print out: Task execution counter */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_a_test_cnt), (int)g_task_a_test_cnt);

		/* Print out: Array of events to excite Task A */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(e_task_a_array), (int)i);

		/* Get the event to excite Task A. */
		event_task_a_test = e_task_a_array[task_a_test_cnt];
		put_event_task_a(event_task_a_test);

		if (task_a_test_cnt < (sizeof(e_task_a_array)/sizeof(e_task_a_t)))
			task_a_test_cnt++;
		else
			task_a_test_cnt = TASK_A_TEST_CNT_INI;
	}

	#if (TEST_X == TEST_1)

	/* Here another code */

	#endif

	#if (TEST_X == TEST_2)

	/* Here Chatbot Artificial Intelligence generated code */

	#endif
}

/********************** end of file ******************************************/
