#ifndef CSTACK_H
#define CSTACK_H

#include "boolean.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

typedef struct cstacknode {
   char data;
   struct cstacknode *next;
} *cstack;

void init_cstack(cstack *);
boolean is_cempty(cstack);
boolean is_cfull(void);
void pushc(cstack *, char);
char popc(cstack *);
void print_cstack(cstack);

#endif
