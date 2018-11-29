/* Min Su Kim, mskim3494 */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw3.h"

int main(int argc, char *argv[])
{
    int l=strlen(argv[1]);
    char dest[l];
    find_replace(argv[1], argv[2],argv[3],dest);
}