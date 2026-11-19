#include <stdio.h>
/* Q7 redesign: prime test checks 2, then only odd candidate divisors. */
int original(unsigned long n,unsigned long *count) {
 *count=0;if(n<2)return 0;
 for(unsigned long i=2;i<=n/i;i++){(*count)++;if(n%i==0)return 0;}
 return 1;
}
int redesigned(unsigned long n,unsigned long *count) {
 *count=0;if(n<2)return 0;
 if(n==2)return 1;
 (*count)++;if(n%2==0)return 0;
 for(unsigned long i=3;i<=n/i;i+=2){(*count)++;if(n%i==0)return 0;}
 return 1;
}
int main(void) {
 unsigned long tests[]={2,3,97,100,7919,1000003};
 puts("ticket original_result original_divisions revised_result revised_divisions saved");
 for(unsigned k=0;k<sizeof(tests)/sizeof(tests[0]);k++) {
   unsigned long a,b;int x=original(tests[k],&a),y=redesigned(tests[k],&b);
   printf("%lu %d %lu %d %lu %ld\n",tests[k],x,a,y,b,(long)a-(long)b);
   if(x!=y)puts("ERROR: mismatch");
 }
 return 0;
}
