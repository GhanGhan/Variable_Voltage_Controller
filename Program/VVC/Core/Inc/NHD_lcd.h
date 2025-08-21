/*
 * NHD_lcd.h
 *
 *  Created on: Aug 21, 2025
 *      Author: Ghani
 */

#ifndef INC_NHD_LCD_H_
#define INC_NHD_LCD_H_


void reset_screen();
void init_screen();
void clear_screen();
void comm_write(uint8_t c);
void data_write(uint8_t d);
void print_data(char* text, uint8_t rowIndex);
void erase_trails(char* text, uint8_t rowIndex);



#endif /* INC_NHD_LCD_H_ */
