#include "expt.h"

/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Lab 1 */

/* Exponentiation by Iteration */
/* compute integer to the nth power given natural n */
long int expt (int a, unsigned int n) {
    if (n == 0){
        return 1;
    }else {
        return a * expt(a, n-1);
    }
}


/* Fast Exponentiation */
/* compute integer to the nth power using successive squaring */
long int ss ( int a , unsigned int n){
  if(n == 0){
    return 1;
  }else if(n == 2){
      return a*a;
  }else if(n%2 == 0){
    return ss(ss(a, n/2), 2);
  } else {
    return a * ss(a, n-1);
  }
}

/* Exponentiation using modulo */
/* compute integer to the nth power using modulo */
int ssm(int a, unsigned int n, unsigned int m){
    if(n == 0){
        return 1;
    }else if(n == 2){
        return (a*a);
    }else if(n%2 == 0){
        return ssm(ssm(a, n/2, m), 2,m)%m;
    } else {
        return a * ssm(a, n-1, m)%m;
    }
}

