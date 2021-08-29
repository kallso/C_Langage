#include <stdio.h>
#include <string.h>

void echanger(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute3(int *a, int *b, int *c) {
    echanger(a, b);
    echanger(a, c);
}

void crypt(char *lettre) {
    // range a - z =  97 - 122
    int decallage = 5;  // le decallage pourrait etre donné en parametre
    int lettreIntValue = *lettre;
    if (*lettre <= 122 - decallage) {
        *lettre += decallage;
    } else {
        *lettre = 96 + (lettreIntValue - (122 - decallage));
    }
}

int main() {
    // -- 1
    int a = 3;
    int b = 2;
    printf("a = %d, b = %d \n", a, b);
    echanger(&a, &b);
    printf("Apres appel a echanger : a = %d, b = %d \n", a, b);

    int c = 1;

    printf("a = %d, b = %d, c = %d \n", a, b, c);
    permute3(&a, &b, &c);
    printf("Apres appel a permute3 : a = %d, b = %d, c = %d \n", a, b, c);

    // -- 2
    char message[128];

    scanf("%s", &message);
    printf("message = %s \n", message);

    for (int i = 0; i < strlen(message); i++) {
        crypt(&message[i]);
    }

    printf("message crypté = %s \n", message);

    return 0;
}
