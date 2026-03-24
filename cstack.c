#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

void init_cstack(cstack *s) {
   *s = NULL;
}

boolean is_cempty(cstack s) {
   if (s == NULL)
      return TRUE;
   else
      return FALSE; 
}

boolean is_cfull(void) {
   cstack temp;
   temp = (cstack) malloc(sizeof (struct cstacknode));
   if (temp == NULL)
      return TRUE;
   else {
      free(temp);
      return FALSE;
   }
}

void pushc(cstack *s, char x) {
   cstack temp;
   temp = (cstack) malloc(sizeof(struct cstacknode));
   temp->data = x;
   temp->next = *s;
   *s = temp;
}

char popc(cstack *s) {
   cstack temp;
   char cpopped;
   temp = *s;
   cpopped = temp->data;
   *s = temp->next;
   free (temp);
   return cpopped; 
}

void print_cstack(cstack s) {
   if(!is_cempty(s)){
      printf("%c\n", s->data);
      print_cstack(s->next); 
   }
}
