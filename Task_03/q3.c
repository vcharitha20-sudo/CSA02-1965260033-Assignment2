#include <stdio.h>
enum { LIGHT=0, FAN=1, AC=2, HEATER=3, PUMP=4 };
unsigned char switch_on(unsigned char reg,int dev) { return (unsigned char)(reg | (1u << dev)); }
unsigned char switch_off(unsigned char reg,int dev) { return (unsigned char)(reg & ~(1u << dev)); }
unsigned char toggle(unsigned char reg,int dev) { return (unsigned char)(reg ^ (1u << dev)); }
int is_on(unsigned char reg,int dev) { return (int)((reg >> dev) & 1u); }

void show(unsigned char reg)
{
    int bit;

    for (bit = 7; bit >= 0; bit--)
    {
        putchar(((reg >> bit) & 1u) ? '1' : '0');
    }

    putchar('\n');
}

int count_on(unsigned char reg)
{
    int n = 0;
    int bit;

    for (bit = 0; bit < 8; bit++)
    {
        n += (reg >> bit) & 1u;
    }

    return n;
}

int main(void) {
    unsigned char reg=0;
    reg=switch_on(reg,LIGHT);printf("after LIGHT on: ");show(reg);
    reg=switch_on(reg,AC);printf("after AC on:    ");show(reg);
    reg=toggle(reg,FAN);printf("after FAN toggle:");show(reg);
    reg=switch_off(reg,LIGHT);printf("after LIGHT off:");show(reg);
    printf("AC is %s, PUMP is %s\n",is_on(reg,AC)?"ON":"OFF",is_on(reg,PUMP)?"ON":"OFF");
    printf("Devices ON = %d\n",count_on(reg));
    return 0;
}
