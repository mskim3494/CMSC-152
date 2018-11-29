/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct squeezed_string squeezed_string;

struct squeezed_string {
    unsigned char *array;
    unsigned int alen;
    unsigned int clen;
};

/* normalize : char -> char */
/* normalizes the char into upper-case */
unsigned char normalize (char c);

/* capitalize : char -> char */
/* capitalize the character, give "garbage" number 28 otherwise */
char capitalize (char c);

void show_binary(unsigned char* s);

void show_ss(squeezed_string *ss);

void write(squeezed_string* ss, unsigned int i, char c);

squeezed_string* squeezed(char* s);

/* squeezed : char -> char* */
/* converts the char into an array with its squeezed equivalent */
unsigned char* binary(unsigned char c);

/* ss_read : squeezed_string, unsigned int -> char */
/* translate the squeezed string into an ASCII char
 * starting from i */
char ss_read(squeezed_string* ss, unsigned int i);

/* ss_write : squeezed_string, unsigned int, char -> void */
/* squeezes the char into the ss starting at point i */
void ss_write(squeezed_string* ss, unsigned int i, char c);

/* squeeze : char* -> squeezed_string* */
/* converts from ASCII code to squeezed string */
squeezed_string* squeeze(char* s);

/* unsqueeze : squeezed_string* -> char* */
/* coverts from a squeezed string* to a ASCII */
char* unsqueeze(squeezed_string* ss);

/* free_squeezed_string : squeezed_string -> void */
/* frees a squeezed string */
void free_squeezed_string(squeezed_string* ss);
