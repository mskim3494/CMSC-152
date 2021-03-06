/* Min Su Kim
 * mskim3494
 * CS152 Winter 2015
 * Project A
 * Feb 2015
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "raytracer.h"

v3 v3_expr(double x, double y, double z)
{
    v3 new;
    new.x=x;
    new.y=y;
    new.z=z;
    return new;
}

/* v3_add : add two vectors */
/* (x,y,z) + (X,Y,Z) = (x+X,y+Y,z+Z) */
v3 v3_add(v3 v1, v3 v2)
{
    v3 newv;
    newv.x= v1.x + v2.x;
    newv.y= v1.y + v2.y;
    newv.z= v1.z + v2.z;
    return newv;
}

/* v3_sub : subtract the second vector from the first */
/* (x,y,z) - (X,Y,Z) = (x-X,y-Y,z-Z) */
v3 v3_sub(v3 v1, v3 v2)
{
    v3 newv;
    newv.x= v1.x - v2.x;
    newv.y= v1.y - v2.y;
    newv.z= v1.z - v2.z;
    return newv;
}

/* v3_neg : negate a vector */
/* -(x,y,z) = (-x,-y,-z) */
v3 v3_neg(v3 v)
{
    v.x= - v.x;
    v.y= - v.y;
    v.z= - v.z;
    return v;
}

/* v3_scale : scale the components of a vector by scalar s */
/* s(x,y,z) = (sx,sy,sz) */
v3 v3_scale(double s, v3 v)
{
    v.x= s * v.x;
    v.y= s * v.y;
    v.z= s * v.z;
    return v;
}

/* v3_dot : compute the dot product of two vectors */
/* (x,y,z) dot (X,Y,Z) = xX+yY+zZ */
double v3_dot(v3 v1, v3 v2)
{
    return (v1.x * v2.x)+(v1.y * v2.y)+(v1.z * v2.z);
}

/* v3_mag : compute the magnitude of a vector */
/* the square root of the sum of the squares of the components */
double v3_mag(v3 v)
{
    return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
}

/* v3_norm : normalize the vector */
/* i.e., a vector pointing in the same direction whose magnitude is 1 */
/* - normalize a vector by scaling by 1 over its magnitude */
/* - if a vector's magnitude is zero, it can't be normalized; return it */
v3 v3_norm(v3 v)
{
    double mag= v3_mag(v);
    if(mag==0){
        return v;
    } else {
        return v3_scale((1/mag),v);
    }
}

double v3_dist(v3 v1, v3 v2)
{
    double a= v1.x-v2.x;
    double b= v1.y-v2.y;
    double c= v1.z-v2.z;
    return sqrt(a*a + b*b + c*c);
}

char *v3_tos(v3 v)
{
    char output[300];
    memset(output, '\0', 300);
    sprintf(output,"(%.2f, %.2f, %.2f)", v.x,v.y,v.z);
    return strdup(output);
}

void v3_show(FILE *f, v3 v)
{
    char* output = v3_tos(v);
    fprintf(f, "%s\n", output);
    free(output);
    return;
}

