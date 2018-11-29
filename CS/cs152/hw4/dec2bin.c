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
    unsigned int a= atoi(argv[1]);
    printf("%s\n", uint_to_binary(a));
    return 0;
}