#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// a simple parser for this BNF grammar:
// expr ::= a | b "," expr

// input token
char tok[10];

// A lexical analyzer splits the input into "tokens".
// This function gets input from standard input and returns
// either the next token as a string, or returns NULL if there
// is no more input.
char *lexan() {
  int n;
  n = scanf("%s", tok);
  if (n == EOF) {
    return NULL;
  }
  return tok;
}

// print an error message and exit
void error(char* msg) {
  printf("%s\n", msg);
  exit(1);
}

// return if standard input follows the syntax for expr,
// else print error message and exit
void expr() {
  char *lookahead;      // the lookahead token

  // get an input token
  lookahead = lexan();

  // the grammar says an expr is either "a" or is "b" "," expr 
  
  // YOUR CODE HERE
  if(lookahead == NULL){
    //error: the input is empty
    error("no");
  }
  
  else if(strcmp(lookahead, "a") == 0){
    // "a" was read
    ;
  }

  else if(strcmp(lookahead, "b") == 0){
    // "b" was read; 
    //printf("%s\n", "good");
    lookahead = lexan();
    if(strcmp(lookahead, ",") != 0 || lookahead == NULL){
      error("no");
    }
    expr();
    //printf("%s\n", "good");
  }

  else{
    error("no");
  }
}

// print 'yes' if standard input follows the syntax for an expr,
// else print 'no'
int main() {
  expr();
  // the input should be one expr only
  if (lexan() != NULL) {
    error("no");
  }
  printf("yes\n");
}

