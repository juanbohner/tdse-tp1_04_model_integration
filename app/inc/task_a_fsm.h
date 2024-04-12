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
 * @file   : task_a_fsm.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef TASK_INC_TASK_A_FSM_H_
#define TASK_INC_TASK_A_FSM_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/
/* Events to excite Task A */
/*
 * 	EVENT_TASK_A_0  --> A_P_ON
 * 	EVENT_TASK_A_1  --> A_P_OFF
 * 	EVENT_TASK_A_2  --> T_I_ON
 * 	EVENT_TASK_A_3  --> T_I_OFF
 * 	EVENT_TASK_A_4  --> T_R_ON
 * 	EVENT_TASK_A_5  --> T_R_OFF
 * 	EVENT_TASK_A_6  --> B_V_ON
 * 	EVENT_TASK_A_7  --> B_V_OFF
 * 	EVENT_TASK_A_8  --> A_E_ON
 * 	EVENT_TASK_A_9  --> A_E_OFF
 * 	EVENT_TASK_A_10 --> B_H_ON
 * 	EVENT_TASK_A_11 --> B_H_OFF
 *
 * 	EVENT_TASK_A_6, EVENT_TASK_A_7, EVENT_TASK_A_8, EVENT_TASK_A_9, EVENT_TASK_A_10, EVENT_TASK_A_11, EVENT_TASK_A_12
 * */

typedef enum e_task_a {EVENT_TASK_A_0, EVENT_TASK_A_1, EVENT_TASK_A_2, EVENT_TASK_A_3, EVENT_TASK_A_4, EVENT_TASK_A_5, EVENT_TASK_A_6, EVENT_TASK_A_7, EVENT_TASK_A_8, EVENT_TASK_A_9, EVENT_TASK_A_10, EVENT_TASK_A_11} e_task_a_t;

/* State of Task A */
typedef enum s_task_a {STATE_TASK_A_0, STATE_TASK_A_1, STATE_TASK_A_2, STATE_TASK_A_3, STATE_TASK_A_4, STATE_TASK_A_5, STATE_TASK_A_6} s_task_a_t;

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_A_FSM_H_ */

/********************** end of file ******************************************/
