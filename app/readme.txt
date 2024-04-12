Example: tdse-tp1_01-system_modeling

 Description:
 Bare Metal - Event-Triggered Systems (ETS)
 App - retarget_printf_to_Console
 Project for STM32 Project (STM32CubeIDE Version: 1.7.0)

  SystemCoreClock     => 64MHz (15.625nS)
  SysTick Rate Hertz  => 1000 ticks per second (1mS)

  app.c (app.h)
   Endless loops, which execute tasks with fixed computing time. This 
   sequential execution is only deviated from when an interrupt event occurs.

  task_a.c (task_a.h, task_a_fsm.h) 
   Non-Blocking Code -> System Modeling -> Excitation for Actuator Modeling

  task_b.c (task_b.h, task_b_fsm.h) 
   Non-Blocking Code -> Actuator Modeling

  task_c.c (task_c.h, task_c_fsm.h) 
   Non-Blocking Code -> Sensor Model-> Excitation for System Model
   
  logger.h (logger.c)
   Utilities for Retarget "printf" to Console

  dwt.h
   Utilities for Mesure "clock cycle" and "execution time" of code
  
  Special connection requirements:
   There are no special connection requirements for this example.

Build procedures:
Visit the Getting started with STM32: STM32 step-by-step at 
"https://wiki.st.com/stm32mcu/wiki/STM32StepByStep:Getting_started_with_STM32_:_STM32_step_by_step"
to get started building STM32 Projects.