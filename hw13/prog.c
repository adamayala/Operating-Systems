#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prog.h"

#define MAX_FIELDS 256

// a program is a statement followed by a program

// constructor for a program
// (prog can be NULL)
PROG *prog_create(STMT *stmt, PROG *prog) {
   PROG *p = (PROG *)malloc(sizeof(PROG));
   p->stmt = stmt;
   p->prog = prog;
   return p;
}

// print this program
void prog_print(PROG *prog) {

   // YOUR CODE HERE
  stmt_print(prog->stmt);
  printf(";");


}

