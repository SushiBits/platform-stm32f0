/*
 * stm32f0xx_it.h
 *
 * STM32F0xx interrupt handler files
 */

#include <stm32f0xx.h>

extern void (*ISR_Vector[])(void);

#define IRQN_HANDLER(id, name) extern void name ##_IRQHandler(void);
#define SKIP_HANDLER(id)
#include <stm32f0xx_handler.h>
#undef IRQN_HANDLER
#undef SKIP_HANDLER

