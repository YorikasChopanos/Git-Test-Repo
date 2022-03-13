#include <stdio.h>
#include <stdlib.h>

// Tountas AEPP selida 100 askisi 88

// gcc -Wall temp_sensors_100_88.c -o exec_100_88
// ./exec_100_88

float a,b,c;

int main(){

    printf("Input the temperatures from the 3 sensors.\n");
    scanf("%2F", &a);
    scanf("%2F", &b);
    scanf("%2F", &c);
    if (a+b+c/3 < 12 || a < 10 || b < 10 || c < 10) { 
        printf("Turn on the AC");
    }
    else{
        printf("Do not turn on the AC\n");
    };
    return 0;
}