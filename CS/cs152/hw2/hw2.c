/* Min Su Kim, mskim3494 */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

/* PROBLEM 1*/
/* adds the first n cubes */
unsigned int sumcubes( unsigned int n)
{
    unsigned int i=n;
    unsigned int acc=0;
    for (i=n; i>0; i--){
        acc += (i * i * i);
    }
    return acc;
}

/* PROBLEM 2 */

/* helper function for ladder */
/* draws part of the ladder (beteen the rungs) */
void betweenrungs (unsigned int rung, unsigned int width, unsigned int between)
{
    unsigned int b= between;
    unsigned int w= width;
    if (rung == 1){ /* if rung, print asterisks*/
        printf("*");
        for (w=width; w>0; w--){
            printf("*");
        } printf("*\n");
    } else if (rung == 0){ /*if not a rung, print spaces */
        for (b=between; b>0; b--){
            printf("*");
            for (w= width; w>0; w--){
                printf(" ");
            } printf("*\n");
        }
    }
}

void ladder (unsigned int rungs, unsigned int width, unsigned int between)
{
    unsigned int i=rungs;
    if (width <= 0 | between <= 0){
        fprintf(stderr, "Negative width or between\n");
        exit(1);
    } else if (rungs <= 0) {
        printf("\n");
    } else {
        for(i=rungs; i>0; i--){
            betweenrungs(0, width, between);
            betweenrungs(1, width, between);
        } betweenrungs (0, width, between);
    }
}

/* PROBLEM 3 */

/* helper function for stairs */
/* draws one step*/
void step (unsigned int steps, unsigned int depth,
           unsigned int riser, unsigned int counter)
{
    unsigned int i=0;
    unsigned int upto= steps*depth;
    unsigned int r=0;
    
    for (r=0; r<riser; r++){
        for (i=0; i<upto; i++){
            printf("*");
        } i= upto;
        for (i=upto; i<counter; i++){
            printf(".");
        }printf("\n");
    }
}

void stairs (unsigned int steps, unsigned int depth, unsigned int riser)
{
    unsigned int i= 0;
    unsigned int c= steps*depth;
    if (depth <= 0 | riser <= 0){
        fprintf(stderr, "Non-positive depth or riser\n");
        exit(1);
    } else if (steps <= 0){
        printf("\n");
    } else {
        for (i=0; i<steps; i++){
            step(i, depth, riser, c);
        }
    }
}

/* PROBLEM 4 */

/* helper function for base_to_int*/
/* exponentiates a by n */
int expt (int a, unsigned int n)
{
    int i=n;
    int acc=1;
    if (n==0){
        return 1;
    } else {
        for (i=n; i>0; i--){
            acc *= a;
        } return acc;
    }
}

int base_to_int(int ndigits, int* digits, int base)
{
    int i= ndigits;
    int acc=0;
    for(i= ndigits; i>0; i--){
        acc += (digits[i-1]*(expt (base, (i-1))));
    } return acc;
}

