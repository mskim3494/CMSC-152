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

poster poster_expr(v3 ulc, double w, double h, rgb(*sc)(v3,v3), rgb sh)
{
    poster new;
    new.upper_left=ulc;
    new.w=w;
    new.h=h;
    new.surface_color=sc;
    new.shine=sh;
    return new;
}

char *poster_tos(poster s)
{
    char output[300];
    memset(output, '\0', 300);
    char* ulc= v3_tos(s.upper_left);
    char* shine= rgb_tos(s.shine);
    sprintf(output,"ulc%s w=%.2f h=%.2f shine%s",
            ulc,s.w,s.h,shine);
    free(ulc);
    free(shine);
    return strdup(output);
}

void poster_show(FILE *f, poster s)
{
    char* output = poster_tos(s);
    fprintf(f, "%s", output);
    free(output);
    return;
}