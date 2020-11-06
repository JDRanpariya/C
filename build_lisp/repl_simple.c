#include <stdio.h>

static char input[2048];

int main(){

    puts("lispy version 0.0.1");
    puts("use ctrl+c to exit\n");

    while(1){

/* outputs prompt */
        fputs("lispy>",stdout);
/* takes stdin and stores in input buffer of 2048 TODO wdym by 2048 */
        fgets(input,2048,stdin);

        printf("no you %s", input);

    }

    return 0;
}
