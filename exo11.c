#include <stdio.h>
#include <string.h>

void computeDays(int *days, int *seconds);
void computeTime(int *days, int *hours, int *minutes, int *seconds);
void computeHours(int *hours, int *seconds);
void computeMinutes(int *minutes, int *seconds);
void clear(int *days, int *hours, int *minutes, int *seconds);

int main() {
    int seconds = 0;
    char *choice = NULL;
    int days = 0, hours = 0, minutes = 0;

    do {
        printf("Entrez un temps en secondes : ");
        scanf("%d", &seconds);

        computeTime(&days, &hours, &minutes, &seconds);
        printf("Ce temps correspond a %i jour(s) %i heure(s) %i minute(s) et %i seconde(s) \n", days, hours, minutes, seconds);

        do {
            printf("Voulez-vous recommencer(o/n) ? ");
            scanf("%ms", &choice);
            clear(&days, &hours, &minutes, &seconds);
        } while (*choice != 'o' && *choice != 'O' && *choice != 'n' && *choice != 'N');

    } while (*choice != 'n' && *choice != 'N');

    return 0;
}

void computeTime(int *days, int *hours, int *minutes, int *seconds) {
    if(*seconds >= 86400) {
        computeDays(days, seconds);
    }
    if(*seconds >= 3600) {
        computeHours(hours, seconds);
    }
    if(*seconds >= 60) {
        computeMinutes(minutes, seconds);
    }
}

void computeDays(int *days, int *seconds) {
    *days = *seconds / 86400;
    *seconds -= *days * 86400;
}

void computeHours(int *hours, int *seconds) {
    *hours = *seconds / 3600;
    *seconds -= *hours * 3600;
}

void computeMinutes(int *minutes, int *seconds) {
    *minutes = *seconds / 60;
    *seconds -= *minutes * 60;
}

void clear(int *days, int *hours, int *minutes, int *seconds) {
    *days = *hours = *minutes = *seconds = 0;
}
