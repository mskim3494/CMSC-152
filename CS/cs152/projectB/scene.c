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

scene new_scene(rgb bg, obj_list *o, light light, rgb amb)
{
    scene new;
    new.bg=bg;
    new.objects=o;
    new.light=light;
    new.amb=amb;
    return new;
}

char *scene_tos(scene sc)
{
    char output[300];
    memset(output, '\0', 300);
    char* bg= rgb_tos(sc.bg);
    char* light= light_tos(sc.light);
    char* amb= rgb_tos(sc.amb);
    sprintf(output,"bg=%slight=%samb=%s",bg, light, amb);
    free(bg);
    free(light);
    free(amb);
    return strdup(output);
}

void scene_show(FILE *f, scene sc)
{
    char* output= scene_tos(sc);
    fprintf(f, "*** scene begin\n");
    fprintf(f, "%s", output);
    ol_show(f,sc.objects);
    fprintf(f,"*** scene end\n");
    free(output);
}