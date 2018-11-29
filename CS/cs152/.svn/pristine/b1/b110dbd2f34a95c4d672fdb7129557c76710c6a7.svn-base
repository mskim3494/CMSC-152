/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "huff.h"

/* HUFFMAN CODE */

char normalize (char c)
{
    if (c<91 && c>64){
        return c-64;
    } else if (c<123 && c>96){
        return c-96;
    } else if (c == 32) {
        return c-32;
    } else {
        return 28;
    }
}

int* count_letters(char* c)
{
    int l= strlen(c);
    int i;
    int* tmp=malloc(28*sizeof(int));
    for(i=0; i<29; i++){
        tmp[i]=0;
    } for(i=0; i<l; i++){
        tmp[(int)normalize(c[i])]+= 1;
    } return tmp;
}

huff *huff_singleton(char c, int n)
{
    huff* tmp= malloc(sizeof(huff));
    leaf leaflet;
    leaflet.c=c;
    leaflet.n=n;
    tmp->tag=LEAF;
    tmp->h.leaf=leaflet;
    return tmp;
}

int huff_weight(huff *h)
{
    switch(h->tag){
        case LEAF :
            return h->h.leaf.n;
            break;
        case NODE :
            return h->h.node.n;
            break;
        default :
            fprintf(stderr, "wrong tag, not hufftree");
            exit(1);
    }
}

huff_list* new_hufflist(huff* h, huff_list* list)
{
    huff_list* tmp= malloc(sizeof(huff_list));
    tmp->h=h;
    tmp->next=list;
    return tmp;
}

huff_list* huff_insert(huff_list* list, huff* h)
{
    if(list->next == NULL){
        if(list->h->tag != LEAF){
            fprintf(stderr, "not leaf!");
            exit(1);
        } else {
            if (huff_weight(h) < huff_weight(list->h)){
                huff_list* tmp= new_hufflist(h, list);
                return tmp;
            } else {
                huff_list* tmp= new_hufflist(h,NULL);
                list->next=tmp;
                return list;
            }
        }
    } else {
        ins_middle(list, list->next, new_hufflist(h,NULL));
        return list;
    }
}

void ins_middle(huff_list* prev, huff_list* rest, huff_list* h)
{
    if(rest->next==NULL){
        if (huff_weight(h->h) < huff_weight(rest->h)){
            prev->next= h;
            h->next=rest;
        } else {
            rest->next=h;
        }
    } else if(huff_weight(h->h) >= huff_weight(rest->h)){
        ins_middle(rest, rest->next, h);
    } else if (huff_weight(h->h) < huff_weight(rest->h)){
        prev->next= h;
        h->next=rest;
    }
}

huff_list* singleton_lst(int* arr)
{
    int i;
    huff_list* new=malloc(sizeof(huff_list));
    new->next=NULL;
    new->h= huff_singleton('i',0);
    for(i=1;i<28;i++){
        if(arr[i] != 0){
            new=huff_insert(new, huff_singleton(i+64,arr[i]));
        }
    } if (arr[0]!=0){
        new=huff_insert(new,huff_singleton(32,arr[0]));
    } return new->next;
}

huff *huff_merge(huff *h1, huff *h2)
{
    huff* nhuff= malloc(sizeof(huff));
    int w1= huff_weight(h1);
    int w2= huff_weight(h2);
    nhuff->tag= NODE;
    if(w1<w2){
        nhuff->h.node.lsub=h1;
        nhuff->h.node.rsub=h2;
    } else {
        nhuff->h.node.rsub=h1;
        nhuff->h.node.lsub=h2;
    } nhuff->h.node.n= huff_weight(h1)+huff_weight(h2);
    return nhuff;
}

huff* final_huff(huff_list* list)
{
    if (list->next == NULL){
        return list->h;
    } else if (list->next->next == NULL){
        return huff_merge(list->h, list->next->h);
    } else {
        return final_huff(new_hufflist(
                    huff_merge(list->h, list->next->h), list->next->next));
    }
}

void huff_lst_free(huff_list* h)
{
    if(h->next == NULL){
        free(h);
    } else {
        huff_lst_free(h->next);
        free(h);
    }
}

void free_huff (huff* h)
{
    switch(h->tag){
        case LEAF :
            free(h);
            break;
        case NODE :
            free_huff(h->h.node.lsub);
            free_huff(h->h.node.rsub);
            free(h);
        default :
            return;
    }
}

huff* huffman_code(char* s)
{
    int* occurences= count_letters(s);
    huff_list* singletons= singleton_lst(occurences);
    return final_huff(singletons);
}

void huff_show(huff *h)
{
    if(h->tag == 0){
        printf("| %c %d | ", h->h.leaf.c, h->h.leaf.n);
    } else if(h->tag == 1){
        printf(" %d \n", h->h.node.n);
        huff_show(h->h.node.lsub);
        huff_show(h->h.node.rsub);
        printf("\n");
    }
}




















