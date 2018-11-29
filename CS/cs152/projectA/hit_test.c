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

hit_test new_ht(int miss, double t, v3 hp, rgb surf, rgb shine, v3 surf_norm)
{
    hit_test new;
    new.miss=miss;
    new.t=t;
    new.hit_point=hp;
    new.surf=surf;
    new.shine=shine;
    new.surf_norm= surf_norm;
    return new;
}

char *hit_test_tos(hit_test t)
{
    char output[300];
    memset(output, '\0', 300);
    sprintf(output, "hit=%u, t=%f\n", t.miss, t.t);
    return strdup(output);
}

void hit_test_show(FILE *f, hit_test t)
{
    char* output= hit_test_tos(t);
    fprintf(f,"%s", output);
    free(output);
}