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

hit_test sphere_intersect(ray r, sphere s)
{
    v3 ro= r.origin;
    v3 rd= r.direction;
    v3 sc= s.center;
    double sr= s.radius;
    v3 A= v3_sub(ro,sc);
    double B= v3_dot(A, rd);
    double C= v3_dot(A, A) - (sr*sr);
    double D= (B*B) -C;
    double t= -B -sqrt(D);
    if(D>0 && t>0){
        v3 hit_point= ray_position(r, t);
        v3 normalized_pos= v3_norm(v3_sub(hit_point, sc));
        rgb surf= (*s.surface_color)(sc, hit_point);
        return new_ht(0, t,hit_point, surf, s.shine, normalized_pos);
    } else if(D>0 && t<=0){
        hit_test missed;
        missed.miss= MISS;
        return missed;
    } else {
        hit_test missed;
        missed.miss= MISS;
        return missed;
    }
}

hit_test poster_intersect(ray r, poster p)
{
    v3 ro= r.origin;
    v3 rd= r.direction;
    v3 n= v3_expr(0,0,-1);
    double d= p.upper_left.z;
    double t= -((v3_dot(ro,n) +d) / (v3_dot(rd,n)));
    v3 hp= ray_position(r,t);
    if(t>0&&(hp.x<(p.upper_left.x+p.w))&&(hp.x>(p.upper_left.x))
       &&(hp.y>(p.upper_left.y-p.h))&&(hp.y<p.upper_left.y)){
        rgb surf= (*p.surface_color)(p.upper_left, hp);
        return new_ht(0, t, hp, surf, p.shine,n);
    } else {
        hit_test to_return;
        to_return.miss= MISS;
        return to_return;
    }
}

hit_test cylinder_intersect(ray r, cylinder c)
{
    v3 ro= r.origin;
    v3 rd= r.direction;
    v3 rp= v3_expr(rd.x,0,rd.z);
    v3 np= v3_norm(rp);
    double mp= v3_mag(rp);
    double xbar= ro.x - c.center.x;
    double zbar= ro.z - c.center.z;
    
    double A= np.x*np.x + np.z*np.z;
    double B= 2*(xbar*np.x + zbar*np.z);
    double C= xbar*xbar + zbar*zbar - c.radius*c.radius;
    double D= (B*B)- (4*A*C);
    
    hit_test to_return;
    to_return.miss= MISS;
    
    if(D>=0){
        double t_front= (-B-sqrt(D))/(2*A);
        double t_back= (-B+sqrt(D))/(2*A);
        v3 p_front= ray_position(r, t_front/mp);
        v3 p_back= ray_position(r, t_back/mp);
        double d_front= v3_dist(p_front, ro);
        double d_back= v3_dist(p_back, ro);
        if((d_front<d_back)&&
           ((p_front.y>=c.center.y)&&(p_front.y<=(c.center.y+c.height)))
           && (t_front > 0)){
            rgb surf=(*c.surface_color)(c.center, p_front);
            v3 norm= v3_norm(v3_sub(p_front,
                                    v3_expr(c.center.x, p_front.y, c.center.z)));
            return new_ht(0, t_front, p_front, surf, c.shine,norm);
        } else if((d_front>d_back)&&
                  ((p_back.y>=c.center.y)&&(p_back.y<=(c.center.y+c.height)))&&
                  (t_back > 0)){
            rgb surf=(*c.surface_color)(c.center, p_back);
            v3 norm= v3_norm(v3_sub(v3_expr(c.center.x, p_back.y, c.center.z),
                                    p_back));
            return new_ht(0, t_back, p_back, surf, c.shine,norm);
        } else {
            return to_return;
        }
    } else {
        return to_return;
    }
}


hit_test intersect(ray r, object obj)
{
    switch(obj.tag){
        case SPHERE :
            return sphere_intersect(r,obj.o.s);
        case POSTER :
            return poster_intersect(r,obj.o.p);
        case CYLINDER :
            return cylinder_intersect(r,obj.o.c);
        default :
            fprintf(stderr, "invalid tag");
            exit(1);
    }
}





