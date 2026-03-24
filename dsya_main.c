#include <stdio.h>
#include <string.h>
#include "dsya_util.h"
#include "dsya.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

int main(void) {
    char input[101];

    printf("Enter an expression: ");
    gets(input);
    printf("%f\n", alg2rpn(input));

    return 0;
}