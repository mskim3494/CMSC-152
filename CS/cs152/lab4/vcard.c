#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard* tmp = malloc(sizeof(vcard));
    tmp->cnet= strdup(cnet);
    tmp->email= strdup(email);
    tmp->fname= strdup(fname);
    tmp->lname= strdup(lname);
    tmp->tel= strdup(tel);
    return tmp;
}

void vcard_free(vcard *c)
{
    free(c->cnet);
    free(c->email);
    free(c->fname);
    free(c->lname);
    free(c->tel);
    free(c);
}

void vcard_show(vcard *c)
{
    printf("CNET: %s\n", c->cnet);
    printf("email: %s\n", c->email);
    printf("fname: %s\n", c->fname);
    printf("lname: %s\n", c->lname);
    printf("tel: %s\n", c->tel);
}
