#include <stdio.h>
#include <string.h>

enum civilites { "M.", "Mme"};

const int tarifHT = 0,004;

typedef struct {
    char *date;
    enum civilites civilite;
    char *prenom;
    char *nom;
    char *adresse;
    int codePostale; // 5 chiffres
    char *ville;
    int tel; // 10 chiffres
    int consoMois;
    int montantFactureTTC;

} factureTelephonique;

int main() {
    return 0;
}
