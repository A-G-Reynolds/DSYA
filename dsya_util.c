#include <stdio.h>
#include <stdlib.h>
#include "dsya_util.h"
#include "boolean.h"

/* 
AUTHOR:  A G Reynolds [2026]
Error 2000. 
*/

boolean is_operator(char c) {
    return ( (c == '+') || (c == '-') || (c == '*') || (c == '/') );
}

boolean is_digit(char c) {
    return ( ( (c>='0')&&(c<='9') ) || (c=='.') );
}

boolean is_space(char c) {
    return (c == ' ');
}

float calculate(float num1, float num2, char opr) {
    float ans;

    switch (opr) {
        case '+': ans = num1 + num2;
            break;
        case '-': ans = num1 - num2;
            break;
        case '*': ans = num1 * num2;
            break;
        case '/': 
            if (num2!=-0)
                ans = num1 / num2;
            else {
                printf("ERROR 2033: Division By Zero.\n");
                exit (0);
            }
            break;
    }
    return ans;
}

boolean precedence(char o1, char o2) {
    int order1, order2;
    switch (o1) {
        case '+': order1 = 2;
            break;
        case '-': order1 = 1;
            break;
        case '*': order1 = 4;
            break;
        case '/': order1 = 3;
            break;
    }
    switch (o2) {
        case '+': order2 = 2;
            break;
        case '-': order2 = 1;
            break;
        case '*': order2 = 4;
            break;
        case '/': order2 = 3;
            break;
    }
    return (order1 <= order2);
}