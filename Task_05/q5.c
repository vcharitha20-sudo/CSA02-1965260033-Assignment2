#include <stdio.h>
unsigned long checks=0;
int is_prime(unsigned long n) {
 checks=0;
 if(n<2) return 0;
 for(unsigned long i=2;i<=n/i;i++) { checks++; if(n%i==0) return 0; }
 return 1;
}
int prime_naive(unsigned long n,unsigned long *c) {
 *c=0;if(n<2)return 0;
 for(unsigned long i=2;i<n;i++){(*c)++;if(n%i==0)return 0;}
 return 1;
}
int prime_while(unsigned long n,unsigned long *c) {
 *c=0;if(n<2)return 0;
 unsigned long i=2;
 while(i<=n/i){(*c)++;if(n%i==0)return 0;i++;}
 return 1;
}
int prime_do_while(unsigned long n,unsigned long *c) {
 *c=0;if(n<2)return 0;
 unsigned long i=2;
 if(n<=3)return 1;
 do {(*c)++;if(n%i==0)return 0;i++;} while(i<=n/i);
 return 1;
}
int main(void) {
 unsigned long tickets[]={2,3,97,100,7919,1000003};
 puts("ticket result naive_checks for_checks while_checks do_while_checks");
 for(unsigned k=0;k<sizeof(tickets)/sizeof(tickets[0]);k++) {
   unsigned long n=tickets[k],a,b,c;
   int p=prime_naive(n,&a),f=is_prime(n);unsigned long fast=checks;
   int w=prime_while(n,&b),d=prime_do_while(n,&c);
   printf("%lu %s %lu %lu %lu %lu\n",n,p?"prime":"not_prime",a,fast,b,c);
   if(p!=f||p!=w||p!=d) puts("ERROR: methods disagree");
 }
 return 0;
}
