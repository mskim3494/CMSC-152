/* Min su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw4.h"

/* PROBLEM 1 */

void adding(char* str, char* newstring, int n)
{
    int i,j;
    j= strlen(str);
    for (i=0; i<j; i++){
        newstring[n++]= str[i];
    } return;
}

char* concat(char** strs, unsigned int nstrs)
{
    int i;
    int n=0;
    int acc=0;
    for (i=0; i< nstrs; i++){
        acc+=strlen(strs[i]);
    }
    char* newstring=malloc(acc); /*correct size? */
    for (i=0; i<nstrs; i++){
        adding(strs[i], newstring, n);
        n+= strlen(strs[i]);
        }
    return newstring;
}

/* PROBLEM 2 */

char* uint_to_binary(unsigned int n)
{
    int i;
    int size=0;
    unsigned int tmp=n;
    while (tmp>0){
        tmp=tmp/2;
        size++;
    }
    char* binary=malloc(size);
    if (n==0){
        binary[0]='0';
        return binary;
    }
    binary[size]='\0';
    for (i=size; i>0; i--){
        if((n%2)==1){
            binary[i-1]='1';
        } else {
            binary[i-1]='0';
        }
        n= n/2;
    }
    return binary;
}

unsigned int binary_to_uint(char* b)
{
    int i;
    int l= strlen(b);
    unsigned int uint=0;
    for (i=0; i<l; i++){
        uint+= (b[i]-48)*pow(2,(l-1)-i);
    }
    return uint;
}

/* PROBLEM 3 */


void analyze_weather(struct observations* observations,
                     unsigned int nobservations,
                     struct climate* climate,
                     struct preferences* preferences,
                     struct compatibility* compatibility)
{
    int i,j,k;
    i=j=k=0;
    compatibility->good_days=0;
    compatibility->bad_days=0;
    compatibility->good_data= malloc(nobservations*sizeof(struct observations*));
    compatibility->bad_data= malloc(nobservations*sizeof(struct observations*));
    getclimate(climate, observations, nobservations);
    for(i=0; i<nobservations; i++){
        if(observations[i].temp>= preferences->temps.min &&
           observations[i].temp<= preferences->temps.max){
            if(observations[i].humid>= preferences->humids.min &&
               observations[i].humid<= preferences->humids.max){
                if(observations[i].wind>= preferences->winds.min &&
                   observations[i].wind<= preferences->winds.max){
                    compatibility->good_days += 1;
                    compatibility->good_data[j++]= &observations[i];
                }else { compatibility->bad_data[k++]=&observations[i];
                }
            }else { compatibility->bad_data[k++]=&observations[i];
            }
        } else { compatibility->bad_data[k++]=&observations[i];
        }
    } compatibility->happiness =
    (double) compatibility->good_days / nobservations;
    compatibility->bad_days =
    nobservations - compatibility->good_days;
}

struct preferences* new_preferences(struct range a, struct range b, struct range c)
{
    struct preferences* tmp=malloc(sizeof(struct preferences));
    tmp->temps= a;
    tmp->humids= b;
    tmp->winds= c;
    return tmp;
}

struct stats makestat(double avg, double min, double max)
{
    struct stats temp;
    temp.avg=avg;
    temp.min=min;
    temp.max=max;
    return temp;
}

double getobs(struct observations* a, int i, int b)
{
    if(b==0){
        return a[i].temp;
    } if (b==1){
        return a[i].humid;
    } if (b==2){
        return a[i].wind;
    } else {
        fprintf(stderr, "wrong input b %d\n", b);
        exit(1);
    }
}

void getclimate(struct climate* clima, struct observations* a, int nobs)
{
    int i,b;
    double avg, max, min;
    struct stats stats[3];
    for (b=0; b<3; b++){
        avg=0.0;
        min= getobs(a,0,b);
        max= getobs(a,0,b);
        for (i=0; i<nobs; i++){
            avg+= getobs(a, i, b);
            if(min > getobs(a, i, b)){
                min = getobs(a, i, b);
            }
            if(max < getobs(a, i, b)){
                max = getobs(a, i, b);
            }
        }avg= avg/nobs;
        stats[b]= makestat(avg, min, max);
    }clima->temps= stats[0];
    clima->humids= stats[1];
    clima->winds= stats[2];
    return;
}

/* PROBLEM 4 */

unsigned int mixture_weight(struct mixture* mixture)
{
    int i;
    double acc=0;
    unsigned int n= mixture->nchemicals;
    for(i=0; i<n; i++){
        acc+= (chemical_weight(mixture->chemicals[i])
               * mixture->moles[i]);
    } return (unsigned int) acc;
}

struct element* new_element(char* name, unsigned int weight)
{
    struct element* tmp= malloc(sizeof(struct element));
    tmp->name= name;
    tmp->weight= weight;
    return tmp;
}

struct molecule* new_molecule(char* name, unsigned int nelements,
                              struct element** elements, unsigned int* atoms)
{
    struct molecule* tmp= malloc(sizeof(struct molecule));
    tmp->name=name;
    tmp->nelements= nelements;
    tmp->elements= elements;
    tmp->atoms= atoms;
    return tmp;
}

struct mixture* new_mixture(char* name, unsigned int nchemicals,
                            struct tagged_chemical* chemicals, double* moles)
{
    struct mixture* tmp= malloc(sizeof(struct mixture));
    tmp->name =name;
    tmp->nchemicals =nchemicals;
    tmp->chemicals =chemicals;
    tmp->moles =moles;
    return tmp;
}

unsigned int chemical_weight (struct tagged_chemical chemtag)
{
    int i,j;
    unsigned int acc=0;
    if(chemtag.tag == 0){
        return chemtag.chemical.element->weight;
    } else if (chemtag.tag == 1) {
        j= chemtag.chemical.molecule->nelements;
        for(i=0; i<j; i++){
            acc+=
                (chemtag.chemical.molecule->elements[i]->weight *
                 chemtag.chemical.molecule->atoms[i]);
        } return acc;
    }
}













