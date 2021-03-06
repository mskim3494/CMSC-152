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

sphere sphere_expr(v3 v, double r, rgb(*sc)(v3,v3), rgb sh)
{
    sphere nsphere;
    nsphere.center=v;
    nsphere.radius=r;
    nsphere.surface_color=sc;
    nsphere.shine= sh;
    return nsphere;
}

char *sphere_tos(sphere s)
{
    char output[300];
    memset(output, '\0', 300);
    char* c= v3_tos(s.center);
    char* shine= rgb_tos(s.shine);
    sprintf(output,"center%s r=%.2f shine%s",
            c, s.radius, shine);
    free(c);
    free(shine);
    return strdup(output);
}

void sphere_show(FILE *f, sphere s)
{
    char* output = sphere_tos(s);
    fprintf(f, "%s", output);
    free(output);
    return;
}

