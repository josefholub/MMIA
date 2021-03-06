/*
 * sct.c
 *
 *  Created on: 15. 10. 2020
 *      Author: josef holub
 */

#include "stm32f0xx.h"
#include "sct.h"

#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)
#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)

void sct_led(uint32_t value)
{
	for(uint8_t j = 0; j < 32; j++)
	{
		sct_sdi(value & 1);
		value >>=1;
		sct_clk(1);
		sct_clk(0);
	}
	sct_nla(1);		// povoleni latch
	sct_nla(0);
}

void sct_init(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER10_0;
	sct_noe(0);
	sct_led(0);
}

void sct_value(uint16_t value)
{
	static const uint32_t reg_value[3][10] = {
	{
		//PCDE--------GFAB @ DIS1
		0b0111000000000111 << 16,	//0
		0b0100000000000001 << 16,	//1
		0b0011000000001011 << 16,	//2
		0b0110000000001011 << 16,	//3
		0b0100000000001101 << 16,	//4
		0b0110000000001110 << 16,	//5
		0b0111000000001110 << 16,	//6
		0b0100000000000011 << 16,	//7
		0b0111000000001111 << 16,	//8
		0b0110000000001111 << 16,	//9
	},
	{
		//----PCDEGFAB---- @ DIS2
		0b0000111101110000 << 0,
		0b0000110000010000 << 0,
		0b0000101110110000 << 0,
		0b0000111010110000 << 0,
		0b0000110011010000 << 0,
		0b0000111011100000 << 0,
		0b0000111111100000 << 0,
		0b0000110000110000 << 0,
		0b0000111111110000 << 0,
		0b0000111011110000 << 0,
	},
	{
		//PCDE--------GFAB @ DIS3
		0b0111000000000111 << 0,
		0b0100000000000001 << 0,
		0b0011000000001011 << 0,
		0b0110000000001011 << 0,
		0b0100000000001101 << 0,
		0b0110000000001110 << 0,
		0b0111000000001110 << 0,
		0b0100000000000011 << 0,
		0b0111000000001111 << 0,
		0b0110000000001111 << 0,
	},
	};

	uint32_t reg =0;

	reg |= reg_value[0][value / 100 % 10];		//stovky
	reg |= reg_value[1][value / 10 % 10];		//desitky
	reg |= reg_value[2][value / 1 % 10];		//jednotky

	sct_led(reg);
}
