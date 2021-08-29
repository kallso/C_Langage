#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

enum {
    INPUT_SIZE = 30
};

/*int main() {
    char *ptr;
    long ret;
    char str[INPUT_SIZE];

    fgets(str, INPUT_SIZE, stdin);
    ret = strtol(str, &ptr, 10);

    if( ret == LONG_MAX || ret == LONG_MIN ) {
        perror("!! Problem is -> ");
    }
    else if (ret) {
        printf("The number is %ld\n", ret);
    }
    else {
        printf("No number found input is -> %s\n", str);
    }

    return 0;
}*/

int main(void) {
    int ti[4];
    int *ptrInt = ti;

    char tc[4]; // ==> String de 4 lettres
    char *ptrChar = tc;

    printf("%lu \n", sizeof(ti));

    char *s3 = "Developpez";
    printf("%p \n", s3);
    printf("%c \n", *s3);

    for (int i = 0; i < strlen(s3); ++i) {
        printf("%c \n", s3[i]);
    }

    for (int i = 0; i < (sizeof ti / sizeof ti[0]); ++i) {
        printf("%i \n", ti[i]);
    }

    int ti2[4] = {0};

    for (int i = 0; i < (sizeof ti2 / sizeof ti2[0]); ++i) {
        printf("%i \n", ti2[i]);
    }

    long ti3[0];

    printf("\n %lu \n", sizeof(ti3));
    printf("%lu \n", sizeof(ti3[0]));
    printf("%lu \n", sizeof(ti3[1]));
    printf("%lu \n", sizeof(ti3[10000]));

    for (int i = 0; i < (sizeof ti3 / sizeof ti3[0]); ++i) {
        printf("%i \n", ti3[i]);
    }

    //pintf("%*d",ti);

    char charExemple;
    short shortExemple;
    int intExemple;
    long longExemple;
    _Bool boolExemple;
    printf("size of a char : %zu \n", sizeof charExemple);
    printf("size of a short : %zu \n", sizeof shortExemple);
    printf("size of an int : %zu \n", sizeof intExemple);
    printf("size of an long : %zu \n", sizeof longExemple);
    printf("size of a bool : %zu \n", sizeof boolExemple);
    printf("size of a size_t : %zu \n", sizeof(size_t));

    // Arrays
    int ai[4] = {1, 2, 3, 4};
    printf("LES SIZE OF\n");
    printf("size of ai %lu \n", sizeof ai);
    printf("size of ai[0] %lu \n", sizeof ai[0]);
    for (int i = 0; i < (sizeof ai / sizeof ai[0]); ++i) {
        printf("%i \n", ai[i]);
    }
    int *aip = ai;
    printf("%i \n", aip[15]);

    printf("valeur de 'o' : %i \n", 'o');
    printf("valeur de 'O' : %i \n", 'O');
    printf("valeur de 'n' : %i \n", 'n');
    printf("valeur de 'N' : %i \n", 'N');
    printf("valeur de 'y' : %i \n", 'y');

    int itest = 10;
    printf("itest : %i \n", itest);

    int *pInttest;

    pInttest = &itest;
    *pInttest = 2021;
    printf("itest : %i \n", itest);

    return 0;
}
