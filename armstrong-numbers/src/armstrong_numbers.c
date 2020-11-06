#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>

bool is_armstrong_number(int num) {

    int count=0;

/* the following loop counts the digits */
    for(int n1=num; n1!=0; n1 /= 10){
        count += 1;
    }

    int result=0,n2=num;

/* this loop add each digit raised to the power of count( ie: digit^count ) to result */
    while(n2 != 0){
        result += pow(n2 % 10, count);
        n2 /= 10;
    }

/* the following line returns true if it's a armstrong_number and vice-versa */
    return result == num;
}


