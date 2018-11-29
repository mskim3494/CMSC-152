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

v3 logical_loc(camera c, unsigned int x, unsigned int y)
{
    v3 new_v3;
    unsigned int h = c.h;
    unsigned int w = c.w;
    if(h>w) {
        new_v3.x = (double)((2.0*x+1.0-w)/h);
        new_v3.y = 1.0-(2.0*y+1.0)/h;
        new_v3.z = 0;
    } else {
        new_v3.x = -1.0+(2.0*x+1.0)/w;
        new_v3.y = (double)(h-2.0*y+1.0)/w;
        new_v3.z = 0;
    }
    return new_v3;
}



int shadow(v3 p, light l, obj_list *objs)
{
    v3 nudge = v3_scale(0.0001, l.direction);
    v3 lifted = v3_add(p, nudge);
    ray r;
    r.origin= lifted;
    r.direction= l.direction;
    obj_list *curr= objs;
    hit_test test;
    while(curr!= NULL){
        test= intersect(r, curr->obj);
        if(test.miss==HIT){
            return 1;
        } else if(test.miss==MISS) {
            curr= curr->next;
        } 
    } return 0;
}

double max(double x, double y)
{
    return (x<y)? y : x;
}

rgb lighting(scene s, ray r, hit_test h)
{
    int num;
    switch(h.miss){
        case MISS :
            return s.bg;
        case HIT :
            num = shadow(h.hit_point, s.light, s.objects);
            if(num==1){
                return rgb_modulate(h.surf, s.amb);
            } else {
                rgb diffused= rgb_scale(max(0.0,v3_dot(h.surf_norm,s.light.direction)),
                                 s.light.color);
                rgb summed= rgb_add(s.amb, diffused);
                rgb k= rgb_modulate(h.surf, summed);
                double nl= v3_dot(h.surf_norm, s.light.direction);
                if(nl > 0){
                    v3 R= v3_sub(v3_scale(2*nl, h.surf_norm), s.light.direction);
                    v3 V= v3_neg(r.direction);
                    double x= pow(max(v3_dot(R,V),0),6);
                    rgb s= rgb_scale(x,h.shine);
                    return rgb_add(k,s);
                } else {
                    return k;
                }
            }
        default :
            fprintf(stderr, "invalid tag");
            exit(1);
    }
}

rgb trace_ray(scene s, ray r)
{
    obj_list* curr= s.objects;
    hit_test test;
    test.miss= MISS;
    test.t= INFINITY;
    while(curr!=NULL){
        hit_test test1= intersect(r, curr->obj);
        if(test1.miss==0){
            if(test1.t < test.t){
                test=test1;
            } curr=curr->next;
        } else {
            curr= curr->next;
        }
    } return lighting(s,r,test);
}

void render(FILE *f, stage g)
{
    int i,j;
    int x= g.c.h;
    int y= g.c.w;
    ray r;
    r.origin= g.c.loc;
    fprintf(f,"P3\n%d %d\n255\n", y, x);
    for(i=0;i<x;i++){
        for(j=0; j<y;j++){
            r.direction= v3_norm(v3_sub(logical_loc(g.c, j,i), r.origin));
            rgb_show_bytes(f, trace_ray(g.s, r));
        }
    }
}

