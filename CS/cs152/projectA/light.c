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

light new_light(v3 d, rgb color)
{
    light new;
    new.direction=d;
    new.color=color;
    return new;
}

char *light_tos(light l)
{
    char output[300];
    memset(output, '\0', 300);
    sprintf(output,"dir(%.2f, %.2f, %.2f) color(%.2f, %.2f, %.2f)\n",
            l.direction.x,l.direction.y,l.direction.z,
            l.color.r,l.color.g,l.color.b);
    return strdup(output);
}

void light_show(FILE *f, light l)
{
    char* output= light_tos(l);
    fprintf(f, "%s", output);
    free(output);
}