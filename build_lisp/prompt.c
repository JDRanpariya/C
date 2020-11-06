#include <stdio.h>
#include <stdlib.h>

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

    puts("lispy version 0.0.1");
    puts("use ctrl+c to exit\n");

    while(1){

/* outputs prompt */
        char* input = readline("replica > ");

/* add history of input */

        add_history(input);

        printf("I literary don't understand wth \"%s\" mean.\n", input);

        free(input);

    }

    return 0;
}
