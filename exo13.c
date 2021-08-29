#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(float a, float b, float c, double *delta, double *x1, double *x2);

float getDelta(float a, float b, float c);

void clear(float *a, float *b, float *c);

int main() {
    float a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0, delta = 0;
    char *choice = NULL;

    do {
        printf("Quels sont les deux nombres à multiplier ? \n");

        do {
            printf("Valeur du coefficient a : ");
            scanf("%f", &a);
            if (a == 0) printf("Veuillez entrer un a non nul \n");
        } while (a == 0);

        printf("Valeur du coefficient b : ");
        scanf("%f", &b);

        printf("Valeur du coefficient c : ");
        scanf("%f", &c);

        calculate(a, b, c, &delta, &x1, &x2);

        printf("delta vaut %.6f \n", delta);
        if (delta < 0) {
            printf("Le discriminant est negatif, il n'existe pas de solution. \n");
        } else if (delta == 0) {
            printf("Le discriminant est nul, il existe une solution: \n");
            printf("x1 = %.6f \n", x1);
        } else {
            printf("Le discriminant est positif, il existe deux solutions: \n");
            printf("x1 = %.6f \n", x1);
            printf("x2 = %.6f \n", x2);
        }

        do {
            printf("Voulez-vous recommencer(o/n) ? ");
            scanf("%ms", &choice);
            clear(&a, &b, &c);
        } while (*choice != 'o' && *choice != 'O' && *choice != 'n' && *choice != 'N');

    } while (*choice != 'n' && *choice != 'N');

    return 0;
}

void calculate(float a, float b, float c, double *delta, double *x1, double *x2) {
    *delta = getDelta(a, b, c);

    if (delta == 0) {
        *x1 = -b / (2 * a);
    } else if (delta > 0) {
        *x1 = (-b + sqrt(*delta)) / (2 * a);
        *x2 = (-b - sqrt(*delta)) / (2 * a);
    }
}

float getDelta(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void clear(float *a, float *b, float *c) {
    *a = *b = *c = 0;
}
