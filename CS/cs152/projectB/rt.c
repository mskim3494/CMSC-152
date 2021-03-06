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

int main(int argc, char *argv[])
{
    if(argc==1){
        stage x1=get_stage(0);
        render(stdout, x1);
        stage_show(stderr, x1);
        return 0;
    } else {
        int i,j;
        i=j=0;
        FILE* f= stdout;
        for(i=1; i<argc;i++){
            if(strcmp(argv[i],"-f")==0){
                f= fopen(argv[i+1],"w");
            }
        } for(i=1;i<argc;i++){
            if(strcmp(argv[i],"-s")==0){
                j=atoi(argv[i+1]);
            }
        }stage x1=get_stage(j);
        render(f, x1);
        fclose(f);
        stage_show(stderr, x1);
        return 0;
    }
}















