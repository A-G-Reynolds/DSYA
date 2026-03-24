#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fstack.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

void init_fstack(fstack *s) {
   *s = NULL;
}

boolean is_fempty(fstack s) {
   if (s == NULL)
      return TRUE;
   else
      return FALSE; 
}

boolean is_ffull(void) {
   fstack temp;
   temp = (fstack) malloc(sizeof (struct fstacknode));
   if (temp == NULL)
      return TRUE;
   else {
      free(temp);
      return FALSE;
   }
}

void pushf(fstack *s, float x) {
   fstack temp;
   temp = (fstack) malloc(sizeof(struct fstacknode));
   temp->data = x;
   temp->next = *s;
   *s = temp;
}

float popf(fstack *s) {
   fstack temp;
   float data_popped;
   temp = *s;
   data_popped = temp->data;
   *s = temp->next;
   free (temp);
   return data_popped; 
}

void print_fstack(fstack s) {
   if(!is_fempty(s)){
      printf("%f\n", s->data);
      print_fstack(s->next); 
   }
}