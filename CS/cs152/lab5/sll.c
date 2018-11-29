/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Lab 5 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>

#include "sll.h"

sll *sll_cons(char *s, sll *ss)
{
    sll* tmp= malloc(sizeof(sll));
    tmp->s=strdup(s);
    tmp->next=ss;
    return tmp;
}

unsigned int sll_length(sll *ss)
{
    if (ss == NULL){
        return 0;
    } else if(ss->next == NULL){
        return 1;
    } else {
        return 1 + sll_length(ss->next);
    }
}

int sll_member(char *s, sll *ss)
{
    if (ss == NULL){
        return 0;
    } else {
        int cmp = strcmp(s, ss->s);
        if (cmp == 0){
            return 1;
        } else {
            return sll_member(s, ss->next);
        }
    }
}

void sll_show(sll *ss)
{
    if (ss==NULL){
        printf("\n");
    } else {
        printf("%s, ", ss->s);
        sll_show(ss->next);
    }
}

void sll_free(sll *ss)
{
    if(ss==NULL){
        return;
    } else {
        sll_free(ss->next);
        free(ss->s);
        free(ss);
    }
}