/* Min Su Kim, mskim3494 */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

void evidence_sumcubes()
{
    printf(" ---- testing sumcubes ---\n");
    printf("n = %d, %d, %d\n", 4, 100, (sumcubes(4)));
    printf("n = %d, %d, %d\n", 2, 9, (sumcubes(2)));
    printf("n = %d, %d, %d\n", 3, 36, (sumcubes(3)));
    printf("n = %d, %d, %d\n", 0, 0, (sumcubes(0)));
}

void evidence_betweenrungs()
{
    printf(" --- testing betweenrungs ---\n");
    printf("eyeball test betweenrungs(1,3,2)\n");
    betweenrungs(1,3,2);
    printf("eyeball test betweenrungs(0,2,3)\n");
    betweenrungs(0,2,3);
}

void evidence_ladder()
{
    printf(" --- testing ladder ---\n");
    printf("eyeball test ladder(5,3,2)\n");
    ladder(5,3,2);
    printf("eyeball test ladder (0,3,2)\n");
    ladder(0,3,2);
    printf("eyeball test ladder(3,3,1)\n");
    ladder(3,3,1);
}

void evidence_step()
{
    printf(" --- testing step ---\n");
    printf("eyeball test step(4,1,1,4)\n");
    step(4,1,1,4);
    printf("eyeball test step(3,3,2,15)\n");
    step(3,3,2,15);
}

void evidence_stairs()
{
    printf(" --- testing stairs ---\n");
    printf("eyeball test stairs(5,3,2)\n");
    stairs(5,3,2);
    printf("eyeball test stairs(3,2,1)\n");
    stairs(3,2,1);
    printf("eyeball test stairs(3,2,1)\n");
    stairs(0,1,1);
    printf("eyeball test stairs(4,1,1)\n");
    stairs(4,1,1);
}

void evidence_expt()
{
    printf(" --- testing expt ---\n");
    printf("- expecting 1: %d\n", expt(2,0));
    printf("- expecting -8: %d\n", expt(-2,3));
    printf("- expecting 27: %d\n", expt(3,3));
    printf("- expecting 128: %d\n", expt(2,7));
}

void evidence_base_to_int()
{
    int digits[] = {2,3,4,5};
    int digits1[] = {5, 6, 7};
    int digits2[] = {7, 6, 5};
    int digits3[] = {-1, -2, -3};
    int digits4[] = {1, 2, 3};
    printf(" --- testing base_to_int ---\n");
    printf("expecting 5432, %d\n", (base_to_int(4, digits, 10)));
    printf("expecting 501, %d\n", (base_to_int(3, digits1, 8)));
    printf("expecting 375, %d\n", (base_to_int(3, digits2, 8)));
    printf("expecting -321, %d\n", (base_to_int(3, digits3, 10)));
    printf("expecting 321, %d\n", (base_to_int(3, digits4, 10)));
}

int main (int argc, char *argv[])
{
    evidence_sumcubes();
    evidence_betweenrungs();
    evidence_ladder();
    evidence_step();
    evidence_stairs();
    evidence_expt();
    evidence_base_to_int();
    return 0;
}