/* expt : int [unsigned int] -> [long int] */
/* linear time recursive exponentiation */
long int expt (int a, unsigned int n);

/* ss : int [unsigned int] -> [long int] */
/* exponentiation by succesive squaring */
long int ss (int a, unsigned int n);

/* ssm : int [unsigned int] [unsigned int] -> int */
/* exponentiation modulo m by succesive squaring */
int ssm (int a, unsigned int n, unsigned int m);
