#include <stdio.h>
#include <string.h>

int main() {
    long t[] = {1005, 307, 1032, 7, 78, 2005, 1035, 732, 1515, 1789, 800, 604};
    long copie[] = {1005, 307, 1032, 7, 78, 2005, 1035, 732, 1515, 1789, 800, 604};
    /*t[2]=((char*)t) + 8 * 8 ; // 1032 c'était l'adresse de la case 8 : 1000 + 4 * 8.
                            // Mais comme ici les cases font 8 octets au lieu de 4 on a 8 * 8
    copie[2]=((char*)t) + 8 * 8 ; // idem que plus haut.*/

    t[2]= t + 8 ; // 1032 c'était l'adresse de la case 8 : 1000 + 4 * 8.
                            // Mais comme ici les cases font 8 octets au lieu de 4 on a 8 * 8
    copie[2]=t + 8; // idem que plus haut.
    /*t[2] = (long)&t[8];
    copie[2] = (long)&t[8];*/

    t[6]=(((char*)t) + 9 * 8) - 1 ; // 1032 c'était l'adresse de la case 8 : 1000 + 4 * 8.
                            // Mais comme ici les cases font 8 octets au lieu de 4 on a 8 * 8
    copie[6]=(((char*)t) + 9 * 8) - 1; // idem que plus haut.


    printf(" %ld \n ", t[4]); // Doit afficher 78;
    printf(" %ld \n ", t); // Doit afficher l'adresse de t[0] donc &t[0] sous forme numerique (a cause de %ld)
    printf(" %ld \n ", &t[4]) ; // Doit afficher l'adresse de t[4] sous forme numerique
    printf(" %ld \n ", *(t+1)) ; // doit afficher la valeur de &t[1] donc t[1] donc 307;
    printf(" %ld \n ", *t+1 ); // doit afficher la valeur de t donc 1005 + 1 donc 1006
    printf(" %ld \n ", *(int *) t[2]);  // cast en adresse t[2] donc 1032 puis dereference 1032 pour acceder a la valeur pointé par l'adresse 1032 (voir le sujet)
    printf(" %ld \n ", t[t[3]]); // t[3] = 7 donc t[t[3]] = t[7] et ce qu iest egale a 732;


    scanf("%ld", t); // doit afficher 0 a la place de 1005
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }

    memcpy(t,copie,sizeof(copie));
    scanf("%ld", &t[4]); // doit afficher 0 a la place de 78 (4eme position)
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", t[2]);   // sera interpeté par scanf comme une adresse malgré que ce soit un int (1032)
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", t+5); // Est equivalent a &t[0+5], doit donc afficher 0 a la place de 2005 (5eme position)
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", &t[5]); // doit afficher 0 a place de 2005 (5eme position)
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", t[6]+1); // doit afficher 0 a place de 1789 car son adresse est de 1036 qui est t[6](1035) + 1
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", &t[6+1]); // doit afficher 0 a la place l'element a la 7eme position (732)
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    memcpy(t,copie,sizeof(copie));
    scanf("%ld", &t[6]+4); // doit afficher 0 a place de 800 car son adresse est de 1040 car t[6](1035) + 4 (x4 long dans ce cas) est egale a 1040.
    for (int i=0; i < (sizeof t / sizeof t[0]); i++) {
        printf("%ld - ", t[i]);
    }
    return 0;
}
