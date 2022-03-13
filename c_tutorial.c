#include <stdio.h>
#include <stdlib.h>

// gcc -Wall c_tutorial.c -o hornerCalculatorExe 
// ./hornerCalculatorExe

int polynomialDegree;
int stableTerm;

int main(){
    printf("Insert degree of polynomial: ");
    scanf("%d", &polynomialDegree);
    int coefficient[polynomialDegree];
    int i;
    for(i = 0; i < polynomialDegree; i++){
        printf("Insert coefficients in the order of decreasing polynomial exponents: ");
        scanf("%d", &coefficient[i]);
    };
    printf("Insert stable term: ");
    scanf("%d", &stableTerm);
    int divisor[stableTerm];
    int j = 1;
    for(i = 0; i < stableTerm; i++){

        if(stableTerm % j == 0){
            divisor[i] = j;
            divisor[i+1] = j*-1;
            printf("\n%d\n", divisor[i]);
            printf("%d", divisor[i+1]);
        };
        j++;
    };
    int remainderIsZero = 0;
    int newCoefficient[polynomialDegree];
    newCoefficient[0] = coefficient[0];
    newCoefficient[1] = (coefficient[0]*divisor[0]) + coefficient[0];
    int z = 0;
    while(remainderIsZero == 0){ 
        for(z = 0; z < sizeof(divisor)/sizeof(divisor[0]);){
            for(i = 2; i < polynomialDegree; i++){
                newCoefficient[i] = (newCoefficient[i-1]*divisor[z]) + coefficient[i];
            
            };
        
        };
    };

};