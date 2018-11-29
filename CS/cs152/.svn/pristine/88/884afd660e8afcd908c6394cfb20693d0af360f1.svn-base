/* Min su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw4.h"

int main (int argc, char *argv[])
{
    int i;
    for(i=0; i<(argc-1); i++){
        argv[i]=argv[i+1];
    }
    char* toprint=concat(argv, argc-1);
    printf("%s\n", toprint);
    free(toprint);
    return 0;
}