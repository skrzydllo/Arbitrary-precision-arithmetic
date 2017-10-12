
/**
 *
 * @file: big_pow.h
 * @Author: Andrzej Skrzydlo
 * @date: 10.12.2017
 * @brief: file holds functions for computing arbitrary-precision number
 * 			x^n using 'Square and Multiply' algorithm
 *
 */

#include <inttypes.h>

typedef uint16_t unit;
#define unit_len sizeof(unit)
#define number_bitlen 512
#define array_len (number_bitlen / (sizeof(unit) * 8))


int pow_big(int, const unit*, int, unit*);
int mul(int, int, const unit*, const unit*, unit*);
void mul_unit_by_unit(unit, unit, unit*, unit*);
