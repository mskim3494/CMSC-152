/* Min Su Kim, mskim3494*/
/* CS152, Winter 2015 */
/* Homework 1 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Problem 1 */

unsigned int gcd( unsigned int a, unsigned int b)
{
    if(a < b){
        return gcd(b,a);
    }
    else if (b == 0){
        return a;
    }
    else {
        return gcd(b, (a % b));
    }
}

/* Problem 2 */

double area_sphere ( double radius )
{
  if ( radius < 0 ) {
    fprintf (stderr, "Negative radius input %f", radius);
  } else {
    return 4 * M_PI * radius * radius;
  }
}

/* Problem 3 */

int early_term_fee (int days)
{
    if ( days < 0 ){
        fprintf ( stderr, "Days cannot be negative, %d", days );
    } else {
    if ( days <= 14 ){
        return 0;
    } else if ( days >= 720 ){
        return 0;
    } else {
        return 325 - ((days / 30) * 10);
    }
    }
}

/* Problem 4 */
 
int is_valid_tel_num ( long long int num )
{
    
    int first,second,third,fourth,fifth;
    
    first = (int) (num / 10E8);
    second = (int) (num / 10E7 - (10*first));
    third = (int) ((num / 10E6)
                   - (10*second)
                   - (100 * first));
    fourth = (int) ((num / 10E5)
                    - (10*third)
                    - (100 * second)
                    - (1000 * first));
    fifth = (int) ((num / 10E4)
                   - (10*fourth)
                   - (100*third)
                   - (1000*second)
                   - (10000*first));
    
    if ( first > 1){
        if ( second == 0 | second == 1){
            if ( fourth > 1 ){
                if ( fifth > 1 ){
                    return 1;
                }
            }
        }
    } else {
        return 0;
    }
    
}

/* Testing the functions */

int main()
{
    printf ("Expect 5, gcd(40,15)=%d\n", gcd(40, 15));
    printf ("Expect 7, gcd(7,77)=%d\n", gcd(7, 77));
    printf ("Expect 3, gcd(3,0)=%d\n", gcd(3, 0));
    printf ("Expect 615.752160, area_sphere(7)=%f\n", area_sphere(7));
    printf ("Expect 0.000000, area_sphere(0)=%f\n", area_sphere(0));
    printf ("Expect 12.566371, area_sphere(1)=%f\n", area_sphere(1));
    printf ("Expect error message for negative input area_sphere(-1)\n",
            area_sphere(-1));
    printf ("Expect 325, early_term_fee(29)=%d\n", early_term_fee(29));
    printf ("Expect 315, early_term_fee(30)=%d\n", early_term_fee(30));
    printf ("Expect 0, early_term_fee(2)=%d\n", early_term_fee(2));
    printf ("Expect 95, early_term_fee(719)=%d\n", early_term_fee(719));
    printf ("Expect 1, is_valid_tel_num(7039833394)=%d\n",
            is_valid_tel_num(7039833394));
    printf ("Expect 1, is_valid_tel_num(3134557875)=%d\n",
            is_valid_tel_num(3134557875));
    printf ("Expect 0, is_valid_tel_num(1134557875)=%d\n",
            is_valid_tel_num(1134557875));
    printf ("Expect 0, is_valid_tel_num(7400833394)=%d\n",
            is_valid_tel_num(7400833394));
    printf ("Expect 0, is_valid_tel_num(7132133394)=%d\n",
            is_valid_tel_num(7132133394));
}

