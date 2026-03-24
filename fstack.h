#ifndef FSTACK_H
#define FSTACK_H

#include "boolean.h"

/* 
AUTHOR:  A G Reynolds [2026]
*/

typedef struct fstacknode {
   float data;
   struct fstacknode *next;
} *fstack;

void init_fstack(fstack *);
boolean is_fempty(fstack);
boolean is_ffull(void);
void pushf(fstack *, float);
float popf(fstack *);
void print_fstack(fstack);

#endif