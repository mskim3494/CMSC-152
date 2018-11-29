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

cylinder cylinder_expr(v3 center, double r, double h, rgb(*sc)(v3,v3), rgb sh)
{
    cylinder new;
    new.center=center;
    new.radius=r;
    new.height=h;
    new.surface_color=sc;
    new.shine=sh;
    return new;
}

char *cylinder_tos(cylinder s) 
{
    char output[300];
    memset(output, '\0', 300);
    char* center= v3_tos(s.center);
    char* shine= rgb_tos(s.shine);
    sprintf(output,"center%s r=%.2f h=%.2f shine%s",
            center,s.radius,s.height,shine);
    free(center);
    free(shine);
    return strdup(output);
}

void cylinder_show(FILE *f, cylinder s)
{
    char* output = cylinder_tos(s);
    fprintf(f, "%s", output);
    free(output);
    return;
}