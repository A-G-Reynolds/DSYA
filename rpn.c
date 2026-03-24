#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fstack.h"
#include "fstack.c"
#include "dsya_util.h"

/* 
AUTHOR:  A G Reynolds [2026]
Error 3000
*/

float rpneval(char *input) {
   int i = -1;
   int nextstate = 0;
   int index = 0;
   fstack top;
   char temp_index[101];
   float num1, num2, ans, digit;

   init_fstack(&top);

   while (1) {
      switch (nextstate) {
         case 0: i++;
            if (is_operator(input[i]))
               nextstate = 1;
            else if (is_digit(input[i]))
               nextstate = 2;
            else if (is_space(input[i]))
               nextstate = 4;
            else if (input[i] == '\0')
               nextstate = 5;
            else
               nextstate = 6;
         break;

         case 1:
            if (!is_fempty(top)) {
               num2 = popf(&top);
               if (!is_fempty(top)) {
                  num1 = popf(&top);
                  if (!is_ffull()) {
                     pushf(&top, calculate(num1, num2, input[i]));
                     nextstate = 0;
                  }
                  else {
                     printf("Error 3044: Stack is Full!\n");
                     exit(0);
                  }
               }
               else {
                  printf("Error 3049: Not Enough Operands!\n");
                  exit(0);
               }
            }
            else {
               printf("Error 3054: Stack is Empty!\n");
               exit(0);
            }
         break;

         case 2:
            temp_index[index++] = input[i];
            i++;
            if (is_digit(input[i]))
               nextstate = 2;
            else
               nextstate = 3;
         break;

         case 3:
            temp_index[index] = '\0';
            sscanf(temp_index, "%f", &digit);
            if (!is_ffull()) {
               pushf(&top, digit);
            }
            else {
               printf("Error 3075: Stack is Full!\n");
               exit(0);
            }
            index = 0;
            i--;
            nextstate = 0;
         break;

         case 4:
            nextstate = 0;
         break;

         case 5:
            if (!is_fempty(top)) {
               ans = popf(&top);
            }
            else {
               printf("Error 3092: No Result on Stack!\n");
               exit(0);
            }
            if (!is_fempty(top)) {
               printf("Error 3096: Invalid RPN!\n");
               exit(0);
            }
            return ans;

         case 6:
            printf("Error 3102: Invalid Input!\n");
            exit(0);
      }
   }
}
