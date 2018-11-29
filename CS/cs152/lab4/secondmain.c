#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "adrbook.h"



void evidence_test()
{
    char cnet[]="hi";
    char cnet1[]="youknow";
    char cnet2[]="doyouknow?";
    char cnet3[]="yuyuknow?";
    char email[]="lol@whatever";
    char fname[]="omg";
    char lname[]="wtf";
    char tel[]="funfunfun";
    vcard* one= vcard_new(cnet,email,fname,lname,tel);
    vcard* twoo= vcard_new(cnet1,email,fname,lname,tel);
    vcard* three= vcard_new(cnet2,email,fname,lname,tel);
    vcard* four= vcard_new(cnet3,email,fname,lname,tel);
    bst* two=bst_singleton(one);
    printf("%d\n", bst_num_entries(two));
    bst_insert(two, twoo);
    printf("%s\n", two->c->email);
    bst_insert(two, three);
    printf("%d\n", bst_num_entries(two));
    printf("%d\n", bst_height(two));
    bst_insert(two, four);
    int m = 10;
    int* n_comparisons= &m;
    vcard* c= bst_search(two, cnet3, n_comparisons);
    printf("comparisons %d\n", m);
    printf("%d\n",bst_c(two, 104));
    vcard* d= bst_search(two, cnet3, n_comparisons);
    printf("%d\n",bst_c(two, 121));
}

int main()
{
    evidence_test();
    return 0;
}