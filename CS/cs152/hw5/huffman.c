/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "huff.h"

int huff_leaves(huff* h)
{
    switch (h->tag){
        case LEAF :
            return 1;
        case NODE :
            return 1 + huff_leaves(h->h.node.lsub)
            + huff_leaves(h->h.node.rsub);
        default :
            fprintf(stderr, "invalid tag");
            exit(1);
    }
}



int main(int argc, char* argv[])
{
    huff* huffman= huffman_code(argv[1]);
    printf("%d\n", huff_leaves(huffman));
    fprintf(stderr, "todo- but brain not working");
    exit(1);
}