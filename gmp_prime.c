#include <gmp.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

int main(){

int status = system("./beep.sh");
char inputStr[1024];
int flag;
int rez;
  /*
     mpz_t is the type defined for GMP integers.  
     It is a pointer to the internals of the GMP integer data structure
testam primalitatea numerelor de forma N = k*2^n+1
cel mai mare numar Proth prim: 10223*pow(2,31172165))+1
   */
printf("#################################################################\n");
printf("#                                                               #\n");
printf("#       Testam primalitatea numerelor de forma N = k*2^n+1      #\n");
printf("#                                                               #\n");
printf("#################################################################\n");
printf("\n");
printf(" TEST 1 : Test de primalitate Miller-Rabin\n");
mpz_t n;
mpz_init(n);
int k, exp;
printf("Enter k: ");
scanf("%d", &k);
printf("Enter n(exponentul): ");
scanf("%d", &exp);
mpz_ui_pow_ui(n,2,exp); // 2^n

mpz_mul_ui(n,n,k); // k * 2^n 

mpz_add_ui(n,n,1); // k*2^n + 1
printf(" N = k*2^n+1 = %d",k);
printf("*2^%d",exp);
printf("+1\n"); 
  

  /*  test de primalitate Miller-Rabin */
/* Return 2 if n is definitely prime, return 1 if n is probably prime (without being certain), or return 0 if n is definitely non-prime */

if(mpz_probab_prime_p(n, 25) == 0) {
 printf (" Rezultat test 1  = 0 (definitely non-prime)\n"); }
if(mpz_probab_prime_p(n, 25) == 1) {
 printf (" Rezultat test 1  = 1 (probably prime)\n"); }
if(mpz_probab_prime_p(n, 25) == 2) {
 printf (" Rezultat test 1  = 2 (definitely prime)\n"); }

printf(" TEST 2 : Test de primalitate bazat pe Teorema lui Proth\n");
mpz_t a; mpz_t rop; unsigned long int  nn; mpz_t b; mpz_t q; mpz_init(q);
mpz_init_set_str (a, "3", 10); //mpz_init_set_str (b, "2", 10);
mpz_init(rop);
//mpz_cdiv_q(q,n-1,b);

mpz_sub_ui(q,n,1); //q=n-1
mpz_cdiv_q_ui(q,q,2); //q=q/2
nn=mpz_get_ui (q);
mpz_powm_ui(rop,a,nn,n);
//printf("nn=%lu\n",nn);
//gmp_printf("q=%Zd\n",q);
gmp_printf (" a^(n-1/2) mod n= %Zd\n", rop);

if(rop == n-1) {  printf(" Rezultat test 2 = este prim\n"); }
else{ printf(" Rezultat test 2 = nu este prim\n");}
  
mpz_clear(n);
int status2 = system("./beep2.sh");
//int progres = system("./progress_bar");

}

