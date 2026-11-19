#include <stdio.h>
static unsigned long calls;
static int verify_card(int has_card) { calls++; return has_card; }
int main(void) {
    unsigned long order_a=0,order_b=0,bitwise=0;
    int i;
    /* Reproducible synthetic set of 1000 passengers. */
    for( i=0;i<1000;i++) {
        int senior=(i%5==0), eligible=(i%3!=0), card=(i%7==0);
        calls=0;
        int a=(senior && eligible) || verify_card(card);
        (void)a;order_a+=calls;
        calls=0;
        int b=verify_card(card) || (senior && eligible);
        (void)b;order_b+=calls;
        calls=0;
        int c=((senior && eligible) | verify_card(card));
        (void)c;bitwise+=calls;
    }
    printf("Passengers: 1000\nSlow calls: cheap checks first = %lu\n",order_a);
    printf("Slow calls: card first = %lu\n",order_b);
    printf("Slow calls: bitwise OR = %lu\n",bitwise);
    calls=0;
    if(0 && verify_card(1)) puts("not reached");
    printf("0 && verify_card: calls=%lu\n",calls);
    calls=0;
    if(1 || verify_card(1)) puts("1 || verify_card: true");
    printf("1 || verify_card: calls=%lu\n",calls);
    calls=0;
    if(0 & verify_card(1)) puts("not reached");
    printf("0 & verify_card: calls=%lu\n",calls);
    return 0;
}
