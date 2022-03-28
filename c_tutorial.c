#include <stdio.h>
#include <stdlib.h>

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
  for (int i = 0; i <= stableTerm * 2; i += 2) {
    if (stableTerm % divisorCounter == 0) {
      divisor[i] = divisorCounter;
      divisor[i + 1] = divisorCounter * -1;
      // printf("%d\n", divisor[i]);
      // printf("%d\n", divisor[i + 1]);
    };
    divisorCounter++;
  };
  int newCoefficients[polynomialDegree];
  int newDivisor;
  int remainder;
  newCoefficients[0] = coefficients[0];
  for (divisorCounter = 0;
       divisorCounter <= sizeof(divisor) / sizeof(divisor[0]);
       divisorCounter++) {
    for (int i = 1; i <= polynomialDegree - 1; i++) {
      newCoefficients[i] =
          (newCoefficients[i - 1] * divisor[divisorCounter]) + coefficients[i];
      remainder = (newCoefficients[2] * divisor[divisorCounter]) + stableTerm;
    };
    if (remainder == 0) {
      printf("Your equation is solved! Here are the coefficients: \n");
      for (int i = 0;
           i < (sizeof(newCoefficients) / sizeof(newCoefficients[0])); i++) {
        printf("%d ", newCoefficients[i]);
      };
      printf("\n");
      break;
    };
  };
};
