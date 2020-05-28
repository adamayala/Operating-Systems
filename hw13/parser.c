#include "lexer.h"
#include "error.h"
#include "expr.h"
#include "stmt.h"
#include "prog.h"

//
// a predictive parser for a super-minimal programming language
//
// refer to the BNF  

// types of functions used below
void match();
PROG *parse(), *prog();

int lookahead;    // most recent token

// check that current token is t, and read next token
void match(int t) { 
    if (lookahead == t)
	lookahead = lexan();
    else error("syntax error");
} 

// parse a program
PROG *parse() {
   PROG *p;
   lookahead = lexan();
   p = prog();
   match(DONE);
   return p;
}

// one or more statements
PROG *prog() {

   // YOUR CODE HERE
  PROG *prog1;
  STMT *stmt;
  char x;

  switch(lookahead){
    case ID:
      x = lexer_id_val();
      match(ID);
      stmt = stmt(x);
      match(";");
      prog1 = prog1(stmt);
      return prog1;
    default:
      error("syntax error");
  }

   // replace the code directly below, which was added so that
   // everything will compile
    
   // EXPR *expr = expr_create_fcall("printf", expr_create_num(22));
   // STMT *stmt = stmt_create_assign("x", expr);
   // PROG *prog = prog_create(stmt, NULL);

   // you will create additional functions in this file for the
   // other non-terminals in your BNF grammar

   return prog;
}

PROG *prog1(){
  PROG *prog1;
  STMT *stmt;
  char x;
  
  switch(lookahead){
    case ID:
      x = lexer_id_val();
      match(ID);
      stmt = stmt(x);
      printf(";");
      prog1 = prog1(stmt);
      return prog1;
    default:
      error("syntax error");
  } 
  return prog; 
}

STMT *stmt(){
  EXPR *expr;
  switch(lookahead){
    case '(':
      match('(');
      expr = expr();
      match(')');
      return expr;
    case '=':
      match('=');
      expr = expr();
      return expr;
    default:
      error("syntax error");
  }
  return stmt;
}

EXPR *expr(){
  EXPR *expr;
  EXPR *expr1;
  char x;
  int i;

  switch(lookahead){
    case ID:
      x = lexer_id_val();
      match(ID);
      expr = expr1();
      return expr;
    case NUM:
      i = lexer_num_val();
      match(NUM);
      return i;
    default:
      error("syntax error");
  }
  return expr;
}

EXPR *expr1(){
  EXPR *expr;

  switch(lookahead){
    case '(':
      match('(');
      expr = expr();
      match(')');
      return expr;
    default:
      error("syntax error");
  }
  return expr;
}
