#include <stdio.h>
#include <stdlib.h>

// gcc -Wall c_tutorial.c -o hornerCalculatorExe 
// ./hornerCalculatorExe

int polynomialDegree;
int stableTerm;
int z;
int i;
void horner(int coefficient[], int divisor[z], int polynomialDegree, int newCoefficient[]) {
    for(int i = 1; i <= polynomialDegree; i++) {
        newCoefficient[i] = (newCoefficient[i-1]*divisor[z]) + coefficient[i]; 
        printf("%d\n", newCoefficient[i]);
    };

};


int main(){
    printf("Insert degree of polynomial: ");
    scanf("%d", &polynomialDegree);
    int coefficient[polynomialDegree];
    for(i = 0; i < polynomialDegree; i++) {

        printf("Insert coefficients in the order of decreasing polynomial exponents: ");
        scanf("%d", &coefficient[i]);
    };

    printf("Insert stable term: ");
    scanf("%d", &stableTerm);
    int divisor[stableTerm];
    int j = 1;
    for(i = 0; i < stableTerm; i++) {

        if(stableTerm % j == 0){
            divisor[i] = j;
            divisor[i+1] = j*-1;
            printf("\n%d\n", divisor[i]);
            printf("%d\n", divisor[i+1]);
        };

        j++;
    };

    int remainderIsZero = 0;
    int newCoefficient[polynomialDegree];
    newCoefficient[0] = coefficient[0];
    newCoefficient[1] = (coefficient[0]*divisor[0]) + coefficient[1];
    int z = 0;
    int divisorArraySize = sizeof(divisor)/sizeof(divisor[0]);
    int *pCoefficient;
    pCoefficient = &coefficient[i];
    int *pDivisor;
    pDivisor = &divisor[z];
    int *pNewCoefficient;
    pNewCoefficient = &newCoefficient[i];
    while( z < divisorArraySize && remainderIsZero == 0 ) {
        horner(pCoefficient, pDivisor, polynomialDegree, pNewCoefficient);     
        if (newCoefficient[divisorArraySize] == 0){
            remainderIsZero = 1;
        } else {
        z++;
        };
    };
};
