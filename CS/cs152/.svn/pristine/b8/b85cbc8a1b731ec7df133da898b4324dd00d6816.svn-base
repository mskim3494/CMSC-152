/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* LINKED LISTS */

typedef struct string_list string_list;
struct string_list {
    char *val;
    string_list *next;
};

/* sl_sorted_asc : [string_list*] -> [int] */
/* determines whether the list is in lexicographic order */
int sl_sorted_asc(string_list *ss);

/* new_sl : [char*] [string_list*] -> [string_list*] */
/* creates a new link */
string_list *new_sl(char *s, string_list *ss);

/* insert : [char*] [string_list*] -> [void] */
/* inserts the string in the proper place in the list */
void insert(char *s, string_list *ss);

/* sl_insert : [char*] [string_list *] -> [string_list*] */
/* inserts the string in the proper place in the list and returns
 * the pointer to the first entry */
string_list *sl_insert(char *s, string_list *ss);

/* destructive_filter : [int(*test)(char*)] [string_list*] [string_list*] -> [void] */
/* destructively filters the list based on the test */
void destructive_filter (int(*test)(char*), string_list *prev, string_list *ss);

/* sl_filter : [int(*test)(char*)] [string_list*] -> [string_list*] */
/* filters the list according to the predicate function
 * and returns the new head value */
string_list *sl_filter(int(*test)(char*), string_list *ss);

/* sample_test : [char*] -> [int] */
/* returns true for strings starting with 'b', false otherwise */
int sample_test(char* s);

/* sl_free : [string_list*] -> [void] */
/* frees a string list */
void sl_free(string_list* ss);