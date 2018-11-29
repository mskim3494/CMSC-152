/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "huff.h"

void first_evidence()
{
    printf(" === testing count_letters === \n");
    char test1[]="sEnSELessness1";
    int* array=count_letters(test1);
    printf("expecting 4, %d\n", array[5]);
    printf("expecting 1, %d\n", array[12]);
    printf("expecting 6, %d\n", array[19]);
    printf("expecting 1, %d\n", array[28]);
    
    printf(" === testing huff_singleton ===\n");
    huff* h1= huff_singleton('L', 1);
    huff* h2= huff_singleton('S', 6);
    printf("expecting L 1, %c %d\n",h1->h.leaf.c, h1->h.leaf.n);
    printf("expecting S 6, %c %d\n",h2->h.leaf.c, h2->h.leaf.n);
    
    printf(" === testing huff_weight === \n");
    printf("expecting 1, %d\n", huff_weight(h1));
    printf("expecting 6, %d\n", huff_weight(h2));
    
    printf(" === testing huff_insert ===\n");
    huff_list* lst_h1= new_hufflist(h1,NULL);
    huff_list* new_lst= huff_insert(lst_h1, h2);
    huff* h3= huff_singleton(5+64,array[5]);
    huff_list* flist= huff_insert(new_lst, h3);
    printf("expecting L 1, %c %d\n", new_lst->h->h.leaf.c, new_lst->h->h.leaf.n);
    printf("expecting E 4, %c %d\n", flist->next->h->h.leaf.c,
           flist->next->h->h.leaf.n);
    
    printf(" === testing singleton_lst ===\n");
    huff_list* hallo= singleton_lst(array);
    printf("expecting L 1, %c %d\n", hallo->h->h.leaf.c,hallo->h->h.leaf.n);
    printf("expecting N 2, %c %d\n", hallo->next->h->h.leaf.c,
           hallo->next->h->h.leaf.n);
    
    printf(" === testing huff_merge ===\n");
    huff* powerhuff= huff_merge(h1,h2);
    printf("expecting NODE=1, %d\n", powerhuff->tag);
    printf("expecting LEAF=0, %d\n", powerhuff->h.node.lsub->tag);
    printf("expecting L, %c\n", powerhuff->h.node.lsub->h.leaf.c);
    printf("expecting 7, %d\n", powerhuff->h.node.n);
    huff_show(powerhuff);
    free(array);
    huff_lst_free(hallo);
    huff_lst_free(flist);
    free_huff(powerhuff);
}


void second_evidence()
{
    char test1[]="sEnSELessness1";
    int* array=count_letters(test1);
    huff_list* hallo= singleton_lst(array);
    printf(" === testing final_huff ===\n");
    printf("expecting S, %c\n",hallo->next->next->next->h->h.leaf.c);
    printf("expecting N, %c\n",hallo->next->next->h->h.leaf.c);
    printf("expecting E, %c\n",hallo->next->h->h.leaf.c);
    printf("expecting L, %c\n",hallo->h->h.leaf.c);
    huff* superpowerhuff= final_huff(hallo);
    printf("expecting 13, %d\n", superpowerhuff->h.node.n);
    printf("expecting S, %c\n", superpowerhuff->h.node.lsub->h.leaf.c);
    printf("expecting 7, %d\n", superpowerhuff->h.node.rsub->h.node.n);
    printf("expecting 13, %d\n", huff_weight(superpowerhuff));
    printf(" === testing huff_show ===\n");
    huff_show(superpowerhuff);
    free(array);
    huff_lst_free(hallo);
    free_huff(superpowerhuff);
}

int main()
{
    first_evidence();
    second_evidence();
    return 0;
}