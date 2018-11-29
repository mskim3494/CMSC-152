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

camera new_camera(v3 loc, unsigned h, unsigned w)
{
    camera new;
    new.loc=loc;
    new.h=h;
    new.w=w;
    return new;
}

char *camera_tos(camera cm)
{
    char output[300];
    memset(output, '\0', 300);
    sprintf(output,"camera(loc(%.2f, %.2f, %.2f) h=%d W=%d)\n",
            cm.loc.x,cm.loc.y,cm.loc.z,cm.h,cm.w);
    return strdup(output);
}

void camera_show(FILE *f, camera cm)
{
    char* output= camera_tos(cm);
    fprintf(f, "%s", output);
    free(output);
}