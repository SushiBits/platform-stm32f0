/*
 * stm32f0xx_it.c
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

#include <stm32f0xx_it.h>
#include <stddef.h>
#include <unistd.h>

void __stack(void);
void Reset_IRQHandler(void);

void (*ISR_Vector[])(void) =
{
		__stack,
		Reset_IRQHandler,
#define IRQN_HANDLER(id, name) name ##_IRQHandler,
#define SKIP_HANDLER(id) NULL,
#include <stm32f0xx_handler.h>
#undef IRQN_HANDLER
#undef SKIP_HANDLER
};

__attribute__((noreturn)) void __start(void);

__attribute__((noreturn)) void Reset_IRQHandler(void)
{
	for (;;);
}

__attribute__((noreturn)) void Default_IRQHandler(void)
{
	for (;;);
}

__attribute__((noreturn)) void _exit(int value)
{
	for (;;);
}

#define IRQN_HANDLER(id, name) __attribute__((weak, alias("Defualt_IRQHandler"))) void name ##_IRQHandler(void);
#define SKIP_HANDLER(id)
#include <stm32f0xx_handler.h>
#undef IRQN_HANDLER
#undef SKIP_HANDLER
