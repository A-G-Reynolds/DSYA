#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstack.h"
#include "dsya_util.h"
#include "rpn.h"

/* 
AUTHOR:  A G Reynolds [2026]
Error 1000.
*/

float alg2rpn(char input[]) {
    int i = -1;
    int o = 0;
    int nextstate = 0;
    cstack top;
    char output[101];
    char o1, o2;

    init_cstack(&top);

    while (1) {
        switch (nextstate) {
            case 0: i++;
                if (is_digit(input[i]))
                    nextstate = 1;
                else if (is_operator(input[i]))
                    nextstate = 2;
                else if (input[i] == '(')
                    nextstate = 3;
                else if (input[i] == ')')
                    nextstate = 4;
                else if (input[i] == '\0')
                    nextstate = 5;
                else
                    nextstate = 6;
                break;
            
            case 1: 
                output[o] = input[i];
                o++;
                i++;
                while (is_digit(input[i])) {
                    output[o] = input[i];
                    o++;
                    i++;
                }
                output[o] = ' ';
                o++;
                i--;
                nextstate = 0;
                break;
            
            case 2:
                while ( (!is_cempty(top)) && (is_operator(top->data)) && (precedence(input[i], top->data)) ) {
                    output[o] = popc(&top);
                    o++;
                    output[o] = ' ';
                    o++;
                }
                if (!is_cfull()) {
                    pushc(&top, input[i]);
                }
                else {
                    printf("ERROR 1061: Full Stack.\n");
                    exit (0);
                }
                nextstate = 0;
                break;
            
            case 3:
                if (!is_cfull()) {
                    pushc(&top, input[i]);
                }
                else {
                    printf("ERROR 1072. Full Stack.\n");
                    exit (0);
                }
                nextstate = 0;
                break;
            
            case 4: 
                while ((!is_cempty(top))&&(top->data != '(')) {
                    output[o] = popc(&top);
                    o++;
                    output[o] = ' ';
                    o++;
                }
                if (!is_cempty(top)) {
                    popc(&top);
                }
                else {
                    printf("ERROR 1090: Mismatch.\n");
                    exit (0);
                }
                nextstate = 0;
                break;

            case 5:
                while ( (!is_cempty(top)) && (is_operator(top->data)) ) {
                    output[o] = popc(&top);
                    o++;
                    output[o] = ' ';
                    o++;
                }
                if (!is_cempty(top)) {
                    popc(&top);
                    printf("ERROR 1105: Invalid Input.\n");
                    exit (0);
                }
                else {
                    output[o] = '\0';
                    return rpneval(output);
                }
                break;
            
            case 6:
                printf("ERROR 1115: Invalid Input.\n");
                exit (0);

        }
    }
}