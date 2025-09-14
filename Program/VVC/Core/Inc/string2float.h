/*
 * string2float.h
 *
 *  Created on: Aug 22, 2025
 *      Author: Ghani
 */

#ifndef INC_STRING2FLOAT_H_
#define INC_STRING2FLOAT_H_

#include <stdint.h>

// Following functions from https://www.geeksforgeeks.org/c/gcvt-convert-float-value-string-c/
void ftoa(float n, char* res, uint8_t afterpoint);
int intToStr(int32_t x, char str[], uint8_t d);
void reverse(char* str, uint8_t len);



#endif /* INC_STRING2FLOAT_H_ */
