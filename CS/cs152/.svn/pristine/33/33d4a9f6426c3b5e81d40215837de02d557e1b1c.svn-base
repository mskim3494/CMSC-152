/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "string_list.h"

/* LINKED LISTS */

void evidence()
{
    printf(" === testing sl_sorted_asc ===\n");
    string_list* sl4= new_sl("waaaa",NULL);
    string_list* sl3= new_sl("sparta!",sl4);
    string_list* sl2= new_sl("is",sl3);
    string_list* sl1= new_sl("this",sl2);
    printf("expecting 0, %d\n",sl_sorted_asc(sl1));
    string_list* sorted3= new_sl("carlos",NULL);
    string_list* sorted2= new_sl("beto",sorted3);
    string_list* sorted1= new_sl("abel",sorted2);
    printf("expecting 1, %d\n",sl_sorted_asc(sorted1));

    printf(" === testing sl_insert ===\n");
    string_list* test= sl_insert("alberto", sorted1);
    printf("expecting alberto, %s\n", test->next->val);
    printf("expecting alberto, %s\n", sorted1->next->val);
    printf("expecting beto, %s\n", test->next->next->val);
    
    printf(" === testing sl_filter ===\n");
    string_list* insert_berta= sl_insert("berta", test);
    int(*fptr)(char*);
    fptr=&sample_test;
    string_list* filter_test= sl_filter(fptr, insert_berta);
    printf("expecting berta, %s\n", filter_test->val);
    printf("expecting beto, %s\n", filter_test->next->val);
    sl_free(sl1);
    sl_free(filter_test);
}

int main()
{
    evidence();
    return 0;
}