/* Min su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw4.h"

void evidence_adding()
{
    char one[]="he";
    char two[]="      ";
    char three[]="hi";
    adding(one, two, 0);
    adding(one, two, 2);
    adding(one, two, 4);
    printf("%s\n", two);
    adding(three, two, 0);
    adding(three, two, 4);
    printf("expecting hihehi -- %s\n",two);
}

void evidence_concat()
{
    printf(" === testing concat === \n");
    char* one[]={"hello, world","abc","123","DEF"};
    char* two[]={"hi"," ","how're ya?"};
    char* three[]={"omg ", "this hw ", "is too ", "loooong"};
    char* print= concat(one,4);
    printf("expecting hello, worldabc123DEF -- %s\n", print);
    print= concat(two, 3);
    printf("expecting hi how're ya? -- %s\n", print);
    print= concat(three, 4);
    printf("expecting omg this hw is too loooong -- %s\n", print);
    free(print);
}

void evidence_uint_to_binary()
{
    printf(" === testing uint to binary === \n");
    char* print= uint_to_binary(0);
    char* print1= uint_to_binary(5);
    char* print2= uint_to_binary(10);
    char* print3= uint_to_binary(100);
    printf("expecting 0, %s\n", print);
    printf("expecting 101, %s\n", print1);
    printf("expecting 1010, %s\n", print2);
    printf("expecting 1100100, %s\n", print3);
    free(print);
    free(print1);
    free(print2);
    free(print3);
}

void evidence_binary_to_uint()
{
    printf(" === testing binary to uint === \n");
    char one[]="1010";
    char two[]="101";
    char thr[]="100101";
    printf("expecting 10, %d\n",binary_to_uint(one));
    printf("expecting 5, %d\n",binary_to_uint(two));
    printf("expecting 37, %d\n",binary_to_uint(thr));
}

void evidence_analyze_weather()
{
    printf(" === testing analyze_weather === \n");
    struct observations one={62.0, 22.0, 40.0};
    struct observations two={91.0, 15.0, 20.0};
    struct observations three={82.0, 20.0, 10.0};
    struct observations four[]={one, two,three};
    struct climate* inputclimate = malloc(sizeof(struct climate));
    struct range range1 = {60.0,85.0};
    struct range range2 = {15.0,21.0};
    struct range range3 = {5.0,25.0};
    struct preferences* initpref = new_preferences(range1, range2, range3);
    struct compatibility* compats = malloc(sizeof(struct compatibility));
    analyze_weather(four, 3, inputclimate, initpref, compats);
    printf("expecting 78.3333, 62, 91 -- %g, %g, %g\n",
           inputclimate->temps.avg, inputclimate->temps.min, inputclimate->temps.max);
    printf("expecting 78.3333, 19, 23.3333 -- %g, %g, %g\n",
           inputclimate->temps.avg, inputclimate->humids.avg, inputclimate->winds.avg);
    printf("expecting 0.333333, 1, 2 -- %g, %d, %d\n",
           compats->happiness, compats->good_days, compats->bad_days);
    printf("expecting 82 -- %g\n", compats->good_data[0]->temp);
    free(inputclimate);
    free(initpref);
    free(compats);
}

void evidence_mixture_weight()
{
    printf(" === testing mixture_weight === \n");
    struct element* e1=new_element("oxygen",16);
    struct element* e2=new_element("hydrogen", 1);
    struct element* e3=new_element("nitrogen", 7);
    struct element* e4=new_element("carbon", 12);
    struct element* e5=new_element("silicone",14);
    struct element* h2o[]={e1,e2};
    struct element* cnsic[]={e4, e3, e5, e4};
    unsigned int nh2o[]={1,2};
    unsigned int ncnsic[]={1,2,1,1};
    struct molecule* m1=new_molecule("h20", 2, h2o, nh2o);
    struct molecule* m2=new_molecule("CNSiC", 4, cnsic, ncnsic);
    struct tagged_chemical tc1={MOLECULE, {m1}};
    struct tagged_chemical tc2={ELEMENT, {e3}};
    struct tagged_chemical tc3={ELEMENT, {e4}};
    struct tagged_chemical tc4={ELEMENT, {e5}};
    struct tagged_chemical tc5={ELEMENT, {e1}};
    struct tagged_chemical tc6={MOLECULE, {m2}};
    struct tagged_chemical test1[]={tc1,tc2,tc3};
    struct tagged_chemical test2[]={tc1, tc2, tc3, tc4,tc5, tc6};
    struct tagged_chemical test3[]={tc2, tc4, tc3};
    double moles1[]={5.0,3.5,10.0};
    double moles2[]={2.0,5.0, 2.0,2.5, 1.0, 2.0};
    double moles3[]={3.0, 0.0, 4.5};
    struct mixture* mix=new_mixture("random", 3, test1, moles1);
    struct mixture* mix2= new_mixture("random", 6, test2, moles2);
    struct mixture* mix3= new_mixture("random", 3, test3, moles3);
    printf("expecting 234 -- %d\n", mixture_weight(mix));
    printf("expecting 250 -- %d\n", mixture_weight(mix2));
    printf("expecting 75 -- %d\n", mixture_weight(mix3));
    free(e1);
    free(e2);
    free(e3);
    free(e4);
    free(m1);
    free(mix);
    free(mix2);
    free(mix3);
}

int main(int argc, char* argv[])
{
    evidence_adding();
    evidence_concat();
    evidence_uint_to_binary();
    evidence_binary_to_uint();
    evidence_analyze_weather();
    evidence_mixture_weight();
    return 0;
}