#include <stdio.h>
#include <stdlib.h>

// gcc -Wall c_tutorial.c -o hornerCalculatorExe 
// ./hornerCalculatorExe


// void horner(int coefficient[], int divisor[z], int polynomialDegree, int newCoefficient[]) {
//     for(int i = 2; i <= polynomialDegree; i++) {
//         newCoefficient[i] = (newCoefficient[i-1]*divisor[z]) + coefficient[i]; 
//         printf("%d\n", newCoefficient[i]);
//     };

// };


int getPolynomialDegree(){
    int polynomialDegree;
    printf("Insert degree of polynomial: ");
    scanf("%d", &polynomialDegree);
    return polynomialDegree;
};


int getCoefficients(){
    int coefficient;
    printf("Insert coefficients in the order of decreasing polynomial exponents: ");
    scanf("%d", &coefficient);
    return coefficient;
};


int getStableTerm(){
    int stableTerm;
    printf("Insert stable term: ");
    scanf("%d", &stableTerm);
    return stableTerm;
};


int findDivisors(int stableTerm, int i, int j){
    if(stableTerm % j == 0){
        return j;
    }
    else{
        return 1;
    };
};

int main() {

    int stableTerm;
    int i;
    int polynomialDegree = getPolynomialDegree();
    int coefficients[polynomialDegree];
    for(i = 0; i < polynomialDegree; i++) {
        coefficients[i] = getCoefficients();
    };

    stableTerm = getStableTerm();
    int divisor[stableTerm];
    int j = 1;
    for(i = 0; i < stableTerm; i++) {
        divisor[i] = findDivisors(stableTerm, i, j);
        divisor[i+1] = divisor[i]*-1;
        i++;
        j++;
    };

//     int remainderIsZero = 0;
//     int newCoefficient[polynomialDegree];
//     newCoefficient[0] = coefficients[0];
//     newCoefficient[1] = (coefficients[0]*divisor[0]) + coefficients[1];
//     int z = 0;
//     int divisorArraySize = sizeof(divisor)/sizeof(divisor[0]);
//     int *pCoefficient;
//     pCoefficient = &coefficients[i];
//     int *pDivisor;
//     pDivisor = &divisor[z];
//     int *pNewCoefficient;
//     pNewCoefficient = &newCoefficient[i];
//     while( z < divisorArraySize && remainderIsZero == 0 ) {
//         horner(pCoefficient, pDivisor, polynomialDegree, pNewCoefficient);     
//         if (newCoefficient[divisorArraySize] == 0){
//             remainderIsZero = 1;
//         } else {
//         z++;
//         };
//     };
};
