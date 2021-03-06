/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Lab 1 */

#include <stdio.h>
#include "expt.h"

void evidence_expt()
{printf("*** testing expt\n");
  printf("- expecting 1: %ld\n", expt(2,0));
  printf("- expecting 8: %ld\n", expt(2,3));
  printf("- expecting 9: %ld\n", expt(3,2));
}

void evidence_ss()
{
  printf("*** testing ss\n");
  printf("- expecting 1: %ld\n", ss(10,0));
  printf("- expecting 16: %ld\n", ss(2,4));
  printf("- expecting 128: %ld\n", ss(2,7));
  printf("- expecting 32: %ld\n", ss(2,5));
  printf("- expecting 3: %ld\n", ss(3,1));
}

void evidence_ssm()
{
    printf("*** testing ssm\n");
    printf("- expecting 6: %d\n", ssm(2,4,10));
    printf("- expecting 24: %d\n", ssm(2,10,1000));
    printf("- expecting 4: %d\n", ssm(3,1000, 7));
}


int main (int argc, char *argv[])
{
  evidence_expt();
  evidence_ss();
  evidence_ssm();
  return 0;
}
