//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

double taxCompute(double income);

int main(void)
{
    double income;
    printf("Enter income : ");
    scanf("%lf", &income);
    printf("Your tax is : %.2f\n", taxCompute(income));
    
    return 0;
}

double taxCompute(double income)
{
    double tax;
    if (income < 750) {
        tax = income * 0.01;
    }
    else if (income < 2250) {
        tax = 7.5 + (income - 750) * 0.02;
    }
    else if (income < 3750) {
        tax = 37.5 + (income - 2250) * 0.03;
    }
    else if (income < 5250) {
        tax = 82.5 + (income - 3750) * 0.04;
    }
    else if (income < 7000) {
        tax = 142.5 + (income - 5250) * 0.05;
    }
    else {
        tax = 230.0 + (income - 7000) * 0.06;
    }
    
    return tax;
    
}
