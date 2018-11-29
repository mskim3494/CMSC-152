/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#ifndef HUFF_H
#define HUFF_H

typedef struct leaf leaf;
typedef struct node node;
typedef struct huff huff;

enum huff_tag { LEAF, NODE };

struct leaf {
    char c;
    int n;
};

struct node {
    int n;
    huff *lsub;
    huff *rsub;
};

union huff_union {
    leaf leaf;
    node node;
};

struct huff {
    enum huff_tag tag;
    union huff_union h;
};

typedef struct huff_list huff_list;
struct huff_list {
    huff* h;
    huff_list* next;
};

/* normalize : [char] -> [char] */
/* normalizes the characters for easy identification */
char normalize (char c);

/* count_letters : [char*] -> [int*] */
/* counts the number of occurences and places them into an
 * array that works as a histogram, space corresponding to 0,
 * A to 1, and so on such that Z = 27, and unsusables go in 29 */
int* count_letters(char* c);

/* Construct a singleton Huffman tree from a character and a count. */
huff *huff_singleton(char c, int n);

/* new_hufflist : [huff*] [huff_list*] -> [huff_list*] */
/* creates a new hufflist that can take another huff_list as input
 * if want a completely new one, list=NULL */
huff_list* new_hufflist(huff* h, huff_list* list);

/* huff_weight : [huff*] -> [int] */
/* Return the weight of a Huffman tree. */
int huff_weight(huff *h);

/* huff_insert : [huff_list*] [huff*] -> [huff_list*] */
/* inserts the huff into the list */
huff_list* huff_insert(huff_list* list, huff* h);

/* ins_middle : [huff_list*] [huff_list*] [huff_list*] -> [void] */
/* helper function for huff_insert */
void ins_middle(huff_list* prev, huff_list* rest, huff_list* h);

/* singleton_lst : [int*] -> [huff_list*] */
/* creates a sorted huff_list from an array with number of occrences */
huff_list* singleton_lst(int* arr);

/* final_huff : [huff_list*] -> [huff*] */
/* merges the huff in the huff_list into a single huff */
huff* final_huff(huff_list* list);

/* huff_merge : [huff*] [huff*] -> [huff*] */
/* Merge two Huffman trees. */
/* See step 2 of the algorithm on the web page for details. */
huff *huff_merge(huff *h1, huff *h2);

/* huffman_code : [char*] -> [huff*] */
/* uses all of the above to create a final huff using the huffman code */
huff* huffman_code(char* s);

/* huff_show : [huff*] -> [void] */
/* Display a Huffman tree at the console. */
/* Essential for development and debugging. */
void huff_show(huff *h);

/* huff_lst_free : [huff_list*] -> [void] */
/* frees a huffman list */
void huff_lst_free(huff_list* h);

/* free_huff : [huff*] -> [void] */
/* frees a huffman tree */
void free_huff (huff* h);

/* finds the number of leaves in the tree */
int huff_leaves(huff* h)

#endif /* HUFF_H */




