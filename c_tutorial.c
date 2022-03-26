#include <stdio.h>
#include <stdlib.h>

// gcc -Wall c_tutorial.c -o hornerCalculatorExe
// ./hornerCalculatorExe

// void horner(int coefficient[], int divisor[z], int polynomialDegree, int
// newCoefficient[]) {
//     for(int i = 2; i <= polynomialDegree; i++) {
//         newCoefficient[i] = (newCoefficient[i-1]*divisor[z]) +
//         coefficient[i]; printf("%d\n", newCoefficient[i]);
//     };

// };

int getPolynomialDegree() {
  int polynomialDegree;
  printf("Insert degree of polynomial: ");
  scanf("%d", &polynomialDegree);
  return polynomialDegree;
};

int getCoefficients() {
  int coefficient;
  printf(
      "Insert coefficients in the order of decreasing polynomial exponents: ");
  scanf("%d", &coefficient);
  return coefficient;
};

int getStableTerm() {
  int stableTerm;
  printf("Insert stable term: ");
  scanf("%d", &stableTerm);
  return stableTerm;
};


int main() {

  int polynomialDegree = getPolynomialDegree();
  int coefficients[polynomialDegree];
  for (int i = 0; i < polynomialDegree; i++) {
    coefficients[i] = getCoefficients();
  };

  int stableTerm = getStableTerm();
  int divisor[stableTerm];
  int divisorCounter = 1;
  for (int i = 0; i <= stableTerm*2; i+=2) {
     if (stableTerm % divisorCounter == 0) {
         divisor[i] = divisorCounter;
         divisor[i+1] = divisorCounter*-1;
         printf("%d\n", divisor[i]);
         printf("%d\n", divisor[i+1]);
     };
     divisorCounter++;
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
