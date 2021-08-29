#include <stdio.h>
#include <string.h>

int calculate(int *a, int *y, int *z);

void Xpair(int *x, int *y);

void Ximpair(int *x, int y, int *z);

void printStep(int x, int y, int z);

void clear(int *a, int *b, int *c);

int main() {
    int x = 0, y = 0, z = 0;
    char *choice = NULL;

    do {
        printf("Quels sont les deux nombres à multiplier ? \n");

        do {
            printf("Entrez le 1er nombre (>0): ");
            scanf("%d", &x);
            if (x < 0) printf("Veuillez entrer un nombre entier positif \n");
        } while (x < 0);

        do {
            printf("Entrez le 2eme nombre (>0): ");
            scanf("%d", &y);
            if (y < 0) printf("Veuillez entrer un nombre entier positif \n");
        } while (y < 0);

        int result = calculate(&x, &y, &z);
        printf("= %i \n", result);
        printf("Le resultat est %i. \n", result);

        do {
            printf("Voulez-vous recommencer(o/n) ? ");
            scanf("%ms", &choice);
            clear(&x, &y, &z);
        } while (*choice != 'o' && *choice != 'O' && *choice != 'n' && *choice != 'N');

    } while (*choice != 'n' && *choice != 'N');

    return 0;
}

int calculate(int *x, int *y, int *z) {
    printStep(*x, *y, *z);
    if (*x == 1) return *x * *y + *z;
    if (*x % 2 == 0) {
        Xpair(x, y);
    } else {
        Ximpair(x, *y, z);
    }
    calculate(x, y, z);
}

void Xpair(int *x, int *y) {
    *x /= 2;
    *y *= 2;
}

void Ximpair(int *x, int y, int *z) {
    *x -= 1;
    *z += y;
}

void printStep(int x, int y, int z) {
    if (z == 0) printf("= %i x %i \n", x, y);
    else printf("= %i x %i + %i \n", x, y, z);
}

void clear(int *x, int *y, int *z) {
    *x = *y = *z = 0;
}
