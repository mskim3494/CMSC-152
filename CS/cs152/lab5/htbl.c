/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Lab 5 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>

#include "htbl.h"
#include "sll.h"

unsigned long int good_hash(char *s)
{
    unsigned long res=17;
    int i,l;
    l= strlen(s);
    for(i=0; i<l; i++){
        res += 37* s[i];
    } return res;
}

/* bad_hash : char -> unsigned int */
/* implement this however you like, as long as it's bad */
unsigned long int bad_hash(char *s)
{
    return strlen(s);
}

/* ht_new : (string -> unsigned long) int -> htbl* */
/* allocate space for a new hash table of given size */
/* all buckets must initially contain the empty list */
htbl *ht_new(unsigned long int(*h)(char*), unsigned int sz)
{
    int i;
    htbl* nhtbl = malloc(sizeof(htbl));
    sll** nbuckets= malloc(sz*sizeof(sll*));
    nhtbl->hash= h;
    nhtbl->n_buckets= sz;
    for(i=0; i<sz; i++){
        nbuckets[i]=NULL;
    } nhtbl->buckets= nbuckets;
    return nhtbl;
}

/* ht_n_entries : htbl* -> unsigned int */
/* return the total number of entries in all buckets */
unsigned int ht_n_entries(htbl *t)
{
    int n_b= t->n_buckets;
    int i;
    int acc=0;
    for(i=0; i<n_b; i++){
        acc+= sll_length(t->buckets[i]);
    } return acc;
}

/* ht_load_factor : htbl* -> float */
/* The load factor is the mean number of elements per bucket. */
double ht_load_factor(htbl *t)
{
    return (float) ht_n_entries(t)/t->n_buckets;
    
}

/* ht_max_bucket : htbl* -> unsigned int */
/* Report the number of items in the fullest bucket. */
/* (Ideally, the max bucket has 1 item in it.) */
unsigned int ht_max_bucket(htbl *t)
{
    int n_b= t->n_buckets;
    int i;
    int max=0;
    for(i=0; i<n_b; i++){
        if(max < sll_length(t->buckets[i])){
            max = sll_length(t->buckets[i]);
        }
    } return max;
}

/* ht_ins : (char*, htbl*) -> int */
/* add string s to hash table t */
/* no special treatment for duplicates, just insert them again */
/* return the number of strings in s's bucket after inserting it */
unsigned int ht_ins(char *s, htbl *t)
{
    int n=(*(t->hash))(s) % t->n_buckets;
    t->buckets[n]=sll_cons(s,t->buckets[n]);
    return sll_length(t->buckets[n]);
}

/* ht_ins_list : (string_list*, htbl*) -> int */
/* add strings to hash table t */
void ht_ins_list(sll *ss, htbl *t)
{
    int i;
    sll* tmp= ss;
    int l= sll_length(ss);
    for(i=0; i<l; i++){
        ht_ins(tmp->s, t);
        tmp=tmp->next;
    }
}

/* ht_member : (char*, htbl*) -> int */
/* test membership of given string in given table */
int ht_member(char *s, htbl *t)
{
    int bucket=(*(t->hash))(s) % t->n_buckets;
    return sll_member(s, t->buckets[bucket]);
}

/* ht_show : htbl* -> <void> */
/* print a representation of the hash table to stdout */
void ht_show(htbl *t)
{
    int l = t->n_buckets;
    int i;
    for(i=0; i<l; i++){
        printf("bucket #%d = ", i);
        sll_show(t->buckets[i]);
    }
}

/* ht_free : htbl* -> <void> */
void ht_free(htbl *t)
{
    int i=0;
    int l= t->n_buckets;
    for(i=0; i<l; i++){
        sll_free(t->buckets[i]);
    } free(t->buckets);
    free(t);
}























