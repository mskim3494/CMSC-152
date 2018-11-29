/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* Homework 3 */

/* PROBLEM 1 */

/* sum : [int*] [int] -> int */
/* sums the values and returns the sum */
int sum(int* a, int alen);

/* squares : [int*] [int] -> void */
/* squares each of the elements of the array */
void squares(int* a, int alen);

/* positives : [int*] [int*] -> void */
/* filters out non-positive values */
void positives(int* a, int* alen);

/* millionaire : [int*] [int] -> [int] */
/* adds up assets and returns true if at least a million */
int millionaire(int* a, int alen);

/* PROBLEM 2 */

/* ati : [char] -> [int] */
/* takes character in ASCII code and returns int equivalent */
/* actual function name ASCII_to_int, but shortened
 * for easier use in str_to_int */
int ati (char ch);

/* random_to_int : [char*] [int] -> [int] */
/* takes a non-decimal and turns into int */
int random_to_int(char* str, int base);

/* str_to_int : [char*] -> [int] */
/* takes a string in this form and returns its value represented as an int*/
int str_to_int(char* str);

/* PROBLEM 3 */

/* equalq : [char*] [int] [char*] -> [int]*/
/* checks for equality */
int equalq(char* a, int i, char* b);

/* find_replace : [char*] [char*] [char*] [char*] -> [void] */
/*takes in a string, a string to search for within that string,
 *a string to replace it with, and a string to store the result in*/
void find_replace(char* src, char* from, char* to, char* dest);
