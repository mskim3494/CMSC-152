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

v3 ray_position(ray r, double t)
{
    return v3_add(r.origin, v3_scale(t, r.direction));
}

char *ray_tos(ray r)
{
    char output[300];
    memset(output, '\0', 300);
    char* vo= v3_tos(r.origin);
    char* vd= v3_tos(r.direction);
    sprintf(output, "origin%s direction%s\n", vo, vd);
    free(vo);
    free(vd);
    return strdup(output);
}

void ray_show(FILE *f, ray r)
{
    char* output= ray_tos(r);
    fprintf(f, "%s",output);
    free(output);
    return;
}