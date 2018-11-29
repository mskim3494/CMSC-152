/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "string_list.h"

/* LINKED LISTS */

int sl_sorted_asc(string_list *ss)
{
    if(ss->next == NULL){
        return 1;
    }
    int cmp= strcmp(ss->val,ss->next->val);
    if (cmp <= 0){
        return sl_sorted_asc(ss->next);
    } else {
        return 0;
    }
}

string_list *new_sl(char *s, string_list *ss)
{
    string_list* tmp = malloc(sizeof(string_list));
    tmp->val=s;
    tmp->next=ss;
    return tmp;
}

void insert(char *s, string_list *ss)
{
    string_list* following = ss->next;
    int cmp=strcmp(s, ss->val);
    if(cmp < 0){
        sl_insert(s, following);
    } else if (cmp > 0){
        string_list* tmp = new_sl(s, following);
        ss->next= tmp;
    }
}

string_list *sl_insert(char *s, string_list *ss)
{
    insert(s,ss);
    return ss;
}

void destructive_filter (int(*test)(char*), string_list *prev, string_list *ss)
{
    if(ss->next == NULL){
        if((*test)(ss->val)==0){
            prev->next=NULL;
            free(ss->next);
            free(ss);
        } else {
            return;
        }
    } else if((*test)(ss->val)!=0){
        destructive_filter((*test), ss, ss->next);
    } else {
        prev->next= ss->next;
        free(ss);
        destructive_filter((*test), prev, ss->next);
    }
}

string_list *sl_filter(int(*test)(char*), string_list *ss)
{
    if (ss->next==NULL){
        if((*test)(ss->val)==0){
            return NULL;
        } else {
            return ss;
        }
    } else if ((*test)(ss->val)==0){
        destructive_filter((*test),ss, ss->next);
        return ss->next;
        free(ss);
    } else {
        destructive_filter((*test),ss,ss->next);
        return ss;
    }
}

int sample_test(char* s)
{
    if (s[0]=='b'){
        return 1;
    } else {
        return 0;
    }
}

void sl_free(string_list* ss)
{
    if(ss->next==NULL){
        free(ss);
        return;
    } else {
        sl_free(ss->next);
        free(ss);
    }
}














