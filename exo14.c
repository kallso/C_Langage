#include <stdio.h>
#include <stddef.h>

int main() {
    int A[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *P;
    P = A;

    for (int i=0; i<=8; i++) {
        printf("%p \n", &A[i]);
    }

    *P+2; // devrait etre 12 + 2 (car P = A = &A[0])
    printf("*P+2 = %d \n", *P+2); // doit afficher 14

    *(P+2);//  devrait etre 34 (car P = A = &A[0]) donc la P + 2 = &A[0+2] donc &A[2]
    printf("*(P+2) = %d \n", *(P+2)); // doit afficher 34

    &P+1;//  sera un nombre quelconque car on ne connait pas l'adresse de P a l'avance
    printf("&P+1 = %p \n", &P+1); // doit afficher l'adresse de P + 1

    &A[4]-3;//  devrait etre l'adresse qui pointe sur la valeur 23 car comme c'est un tableau et que les adresses
    // des elements du tableau sont concecutives si on retranche a l'adresse de &A[4] le nombre 3 on obtient l'adresse
    // de A[1]
    printf("&A[4]-3 = %p ET sa valeur est : %d donc c'est bien l'adresse de A[1] \n", &A[4]-3, *(&A[4]-3));
    // doit afficher l'adresse de A[1] ainsi que la valeur 23 pour verifier

    A+3;//  Meme raisonement que precedament donc on devrait avoir l'adresse qui pointe vers le nombre 45
    printf("A+3 = %p ET sa valeur est : %d donc c'est bien l'adresse de A[3] \n", A+3, *(A+3)); // doit afficher l'adresse de 45 et le nombre 45 pour verifier

    ptrdiff_t diff = &A[7]-P;//  P = &A[0] donc &A[7] - &A[0] = 7
    printf("&A[7]-P = %td (difference entre les deux adresses) \n", diff); // doit afficher le nombre 7 car la difference entre deux pointeurs
    // retourne un nombre et non pas une adresse. ce nombre a meme un type : ptrdiff_t    défini dans   stddef.h.

    P+(*P-10); // (*P-10) : on soustrait 10 a la valeur pointée par P, donc A[0] donc 12 et - 10 = 2.
    // Ensuite on ajoute 2 a P donc a &A[0] on obtient donc &A[2]
    printf("P+(*P-10) = %p ET sa valeur est : %d donc c'est bien l'adresse de A[2] \n", P+(*P-10), *(P+(*P-10)));

    *(P+*(P+8)-A[7]); // Le premier calcul est (P + 8) qui donne &A[0] + 8 donc &A[8]
    // Ensuite on applique le "*" donc on prends la valeur pointé par &A[8] qui est 90
    // Maintenat on va de la guache vers la droite dans la plus grande parenthese donc on va caculer (P+*(P+8)-A[7])
    // Ce qui fait &A[0] + 90 - 89 =   &A[0] + 1 = &A[1]
    // Puis on applique le "*" qui nous demande de prendre la valeur pointée par l'adresse &A[1] et qui est 23.
    // La valeur finale est donc 23.
    printf("*(P+*(P+8)-A[7]) = %d \n", *(P+*(P+8)-A[7])); // Doit afficher 23.

    return 0;
}

