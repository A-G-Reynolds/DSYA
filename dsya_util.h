#ifndef DSYA_UTIL_H
#define DSYA_UTIL_H

#include "boolean.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

boolean is_operator(char);
boolean is_digit(char);
boolean is_space(char);
float calculate(float, float, char);
boolean precedence(char, char);

#endif
