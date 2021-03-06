/*
 * sct.c
 *
 *  Created on: 15. 10. 2020
 *      Author: josef holub
 */

#include "stm32f0xx.h"
#include "sct.h"
#include "main.h"

void sct_led(uint32_t value)
{
	for(uint8_t j = 0; j < 32; j++)
	{
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, (value & 1));
		value >>=1;
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);
	}
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 1);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 0);

}

void sct_init(void)
{
	HAL_GPIO_WritePin(SCT_NOE_GPIO_Port, SCT_NOE_Pin, 0);
	sct_led(0);
}

void sct_value(uint16_t value, uint8_t led)
{
	static const uint32_t reg_value[4][10] = {
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
		0b0000011101110000 << 0,
		0b0000010000010000 << 0,
		0b0000001110110000 << 0,
		0b0000011010110000 << 0,
		0b0000010011010000 << 0,
		0b0000011011100000 << 0,
		0b0000011111100000 << 0,
		0b0000010000110000 << 0,
		0b0000011111110000 << 0,
		0b0000011011110000 << 0,
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
	{
	    //----43215678---- @ LED
		0b0000000000000000 << 16,	//0
		0b0000000100000000 << 16,	//1
		0b0000001100000000 << 16,	//2
		0b0000011100000000 << 16,	//3
		0b0000111100000000 << 16,	//4
		0b0000111110000000 << 16,	//5
		0b0000111111000000 << 16,	//6
		0b0000111111100000 << 16,	//7
		0b0000111111110000 << 16,	//8
	},
	};

	uint32_t reg =0;

	reg |= reg_value[0][value / 100 % 10];		//stovky
	reg |= reg_value[1][value / 10 % 10];		//desitky
	reg |= reg_value[2][value / 1 % 10];		//jednotky
	reg |= reg_value[3][led];					//led bar graf

	sct_led(reg);
}
