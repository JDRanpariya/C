#include "armstrong_numbers.h"
#include <stdio.h>

bool is_armstrong_number(int num) {

    int n1,count=1,result;

    n1 = num;

    while(n1 != 0){
        n1 = n1/10;
        result += count*(num % 10);
        count+=1;
    }

    if ( result == num ){
        return true; 
    }
    else{
       return false; 
    }

}


