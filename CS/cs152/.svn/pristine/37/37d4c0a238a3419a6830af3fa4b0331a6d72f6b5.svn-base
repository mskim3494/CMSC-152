/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Lab 3 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sinsquare.h"

int sinsquare(int side, float r, float g, float b)
{
  int i,j, red, green, blue;
  double distance;
  float x=(255/2.0);
  printf("P3\n%d %d\n255\n",side,side);
  for (i=0; i<side; i++){
    for (j=0; j<side; j++){
      distance=  sqrt(pow(((side/2.0)-i),2) + pow(((side/2.0)-j),2));
      red= (int)(x*sin(r*distance) + x);
      blue= (int)(x*sin(b*distance) + x);
      green= (int) (x*sin(g*distance) + x);
      printf("%d,%d,%d\n",red,green,blue);
    }
  } return 0;
}

int main(int argc, char *argv[])
{
  float r=1.0;
  float g=1.0;
  float b=1.0;
  int side=480;
  int k;
  for(k=1; k<argc; k++){
    if(!strcmp(argv[k], "-s")){
      side=atoi(argv[k+1]);
    } else if (!strcmp(argv[k], "-r")){
      r=atof(argv[k+1]);
    } else if (!strcmp(argv[k], "-g")){
      g=atof(argv[k+1]);
    } else if (!strcmp(argv[k], "-b")){
      b=atof(argv[k+1]);
    }
  } 
   sinsquare(side, r, g, b);
   return 0;
}
