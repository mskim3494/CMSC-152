/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "ss.h"

void error(char* s) {
    fprintf(stderr, s);
    exit(1);
}

char i2c(unsigned int i) {
    if (i == 0) {
        return ' ';
    }
    if (i > 26) {
        error("invalid char integer value\n");
    }
    return 'A' + i - 1;
}

unsigned int c2i(char c) {
    if (c == ' ') {
        return 0;
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 1;
    } else if ('a' <= c && c <= 'z') {
        return c - 'a' + 1;
    } else {
        error("invalid char to turn into integer\n");
    }
}

char ss_read(squeezed_string* ss, unsigned int i) {
    if (i >= ss->clen) {
        error("read index out of bounds\n");
    }
    unsigned int high = i*5;
    unsigned int low  = (i+1)*5-1;
    unsigned int low_index  = low/8;
    unsigned int high_index = high/8;
    unsigned int low_data = ss->array[low_index];
    unsigned int high_data = ss->array[high_index];
    unsigned short combo = low_data | (unsigned short)high_data<<8;
    unsigned int char_data = combo>>((low_index+1)*8 - low - 1) & 31;
    return i2c(char_data);
}

void ss_write(squeezed_string* ss, unsigned int i, char c) {
    if (i >= ss->clen) {
        error("write index out of bounds\n");
    }
    unsigned int high = i*5;
    unsigned int low  = (i+1)*5-1;
    unsigned int low_index  = low/8;
    unsigned int high_index = high/8;
    unsigned int low_data = ss->array[low_index];
    unsigned int high_data = ss->array[high_index];
    unsigned short combo = low_data | (unsigned short)high_data<<8;
    int shift = (low_index+1)*8 - low - 1;
    combo &= ~(31<<shift);
    combo |= (unsigned short)c2i(c)<<shift;
    ss->array[low_index] = combo;
    if (high_index != low_index) {
        ss->array[high_index] = combo>>8;
    }
}

char* filter(char* s) {
    char* r = malloc(strlen(s)+1);
    char* t = r;
    int b = 0;
    while (*s) {
        if (*s == ' ' || ('a' <= *s && *s <= 'z') || ('A' <= *s && *s <= 'Z')) {
            t[0-b] = *s;
        } else {
            b++;
        }
        s++;
        t++;
    }
    *t = '\0';
    return r;
}

squeezed_string* squeeze(char* s) {
    s = filter(s);
    char* sf = s;
    int len = strlen(s);
    squeezed_string* ss = malloc(sizeof(squeezed_string));
    ss->clen = len;
    len = (len*5)/8 + (((len*5)%8)?1:0);
    ss->alen = len;
    ss->array = malloc(len);
    int i = 0;
    while (*s) {
        ss_write(ss, i, *s);
        i++;
        s++;
    }
    free(sf);
    return ss;
}

char* unsqueeze(squeezed_string* ss) {
    char* s = malloc(ss->clen + 1);
    int i;
    for (i = 0; i < ss->clen; i++) {
        s[i] = ss_read(ss, i);
    }
    s[i] = '\0';
    return s;
}
}

void free_squeezed_string(squeezed_string* ss)
{
    free(ss->array);
    free(ss);
}