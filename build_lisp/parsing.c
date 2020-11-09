#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else

#include <readline/history.h>
#include <readline/readline.h>

#endif

int main(int argc, char** argv){

/* create some parsers */
mpc_parser_t* Number = mpc_new("number");
mpc_parser_t* Operator = mpc_new("operator");
mpc_parser_t* Expr = mpc_new("expr");
mpc_parser_t* Replica = mpc_new("replica");

/* define them from following language */
mpca_lang(MPCA_LANG_DEFAULT,
    "number   : /-?[0-9]+/ ;                         "
    "operator : '+' | '-' | '*' | '/';                "
    "expr     : <number> | '('<operator> <expr>+ ')'; "
    "replica  : /^/ <operator> <expr>+ /$/;           ",
Number, Operator, Expr, Replica);

    puts("lispy version 0.0.1");
    puts("use ctrl+c to exit\n");

    while(1){

/* outputs prompt */
        char* input = readline("replica > ");

/* add history of input */

        add_history(input);

        /* printf("I literary don't understand wth \"%s\" mean.\n", input); */
       /* Attempt to Parse the user Input */
    mpc_result_t r;
        if (mpc_parse("<stdin>", input, Replica, &r)) {
      /* On Success Print the AST */
          mpc_ast_print(r.output);
          mpc_ast_delete(r.output);
        } else {
          /* Otherwise Print the Error */
              mpc_err_print(r.error);
              mpc_err_delete(r.error);
        } 

        free(input);

    }

/* Undefine and Delete our Parsers */
mpc_cleanup(4, Number, Operator, Expr, Replica);

    return 0;
}
