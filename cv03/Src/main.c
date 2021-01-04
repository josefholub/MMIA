/**
 ******************************************************************************
 * @file           : main.c
 * @author         : josefholub, https://github.com/josefholub/MMIA
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stm32f0xx.h"
#include "sct.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	sct_init();
	sct_led(0x7A5C36DE);
	for(volatile uint32_t j = 0; j < 400000; j++)
	{
		// cekani aby se robrazilo bye citelne
	}

    /* Loop forever */
	for(;;)
	{
		for(uint16_t i = 0; i < 1000; i += 111)
		{
			sct_value(i);										//zobrazovani postupne hodnot 000,111,222,...,999
			for(volatile uint32_t j = 0; j < 100000; j++)
				{
					// cekani aby se cislice daly precist
				}
		}
	}
}
