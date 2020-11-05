#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>

bool is_armstrong_number(int num) {

    int n1,count=0,result=0,n2;

    n1 = num;
    n2 = num;
/* the following loop counts the digits */
    while(n1 != 0){
        n1 = n1/10;
        count+=1;
    }
/* this loop add each count*digit to result */
    while(n2 != 0){
        result += pow(n2 % 10, count);
        n2 = n2/10;
    }

/* the following conditional checks if it's a armstrong_number */
    if ( result == num ){
        return true; 
    }
    else{
       return false; 
    }

}


