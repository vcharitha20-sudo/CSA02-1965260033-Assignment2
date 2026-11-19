#include <stdio.h>
/* All money values here are whole rupees, for demonstrating integer division. */
int main(void) {
    struct Bill { int price, qty, senior; } bills[]={{100,2,1},{500,3,1},{250,2,0}};
    int count=0;
    int i;
    puts("price qty senior | original_total original_net | corrected_total corrected_net");
    for (i=0;i<3;i++) {
        int price=bills[i].price, qty=bills[i].qty, senior=bills[i].senior;
        int total=price*qty-price*qty*15/100*senior+price*qty*5/100;
        int net=total>1000?total-50:total;
        int gross=price*qty;
        int discount=senior?(gross*15)/100:0;
        int discounted=gross-discount;
        /* Design choice: GST is calculated on the discounted amount. */
        int gst=(discounted*5+50)/100;
        int corrected_total=discounted+gst;
        int corrected_net=corrected_total>1000?corrected_total-50:corrected_total;
        printf("%5d %3d %6d | %14d %12d | %15d %13d\n",price,qty,senior,total,net,corrected_total,corrected_net);
    }
    /* Never evaluate count = count++ + 1: it has undefined behavior. */
    count++;
    printf("Safe increment: count = %d\n",count);
    return 0;
}
