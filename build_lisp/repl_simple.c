#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

/* #include <editline/readline.h> */
/* #include <editline/history.h> */


int main(int argc, char** argv){

    puts("lispy version 0.0.1");
    puts("use ctrl+c to exit\n");

    while(1){

/* outputs prompt */
        char* input = readline("lispy> ");

/* add history of input */

        add_history(input);


        printf("no you %s\n", input);

        free(input);

    }

    return 0;
}
