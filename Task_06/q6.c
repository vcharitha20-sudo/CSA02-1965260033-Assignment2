#include <stdio.h>
#include <limits.h>
/* Work in integer paise. Monthly interest is rounded to nearest paise. */
int main(void) {
    long long principal, payment, balance, interest_total=0;
    int rate_basis_points; /* 200 means 2% per month */
    printf("Enter principal (rupees), monthly rate (basis points), payment (rupees): ");
    long long rupees, monthly_rupees;
    if(scanf("%lld %d %lld",&rupees,&rate_basis_points,&monthly_rupees)!=3 ||
       rupees<=0 || monthly_rupees<=0 || rate_basis_points<0 || rate_basis_points>10000 ||
       rupees>LLONG_MAX/100 || monthly_rupees>LLONG_MAX/100) {
       puts("Invalid input");return 1;
    }
    principal=rupees*100;payment=monthly_rupees*100;balance=principal;
    puts("Month | Interest (Rs) | Payment (Rs) | Balance (Rs)");
    int month;
    for(month=1;month<=360 && balance>0;month++) {
       if(balance>(LLONG_MAX-5000)/10000) { puts("Balance too large");return 1; }
       long long interest=(balance*rate_basis_points+5000)/10000;
       if(interest>LLONG_MAX-balance || interest>LLONG_MAX-interest_total) { puts("Overflow");return 1; }
       long long due=balance+interest;
       if(payment<=interest) { puts("Payment does not exceed interest; loan will not reduce");return 1; }
       long long paid=payment<due?payment:due;
       balance=due-paid;interest_total+=interest;
       printf("%5d | %8lld.%02lld | %8lld.%02lld | %8lld.%02lld\n",month,interest/100,interest%100,paid/100,paid%100,balance/100,balance%100);
    }
    if(balance>0) puts("Stopped at safety limit of 360 months; balance remains.");
    else printf("Repaid in %d months; total interest Rs %lld.%02lld\n",month-1,interest_total/100,interest_total%100);
    return 0;
}
