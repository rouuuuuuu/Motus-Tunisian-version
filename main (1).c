#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "couleur.h"
#include "admin.h"
#include "default.h"
#include "supprimer.h"
#include "solo.h"
#include "duo.h"
#include "theme.h"

int main() {
           int mode;     int theme ;
    printf("aaslema,bienvenue dans le jeu motus btounsi ");

    do {
       srand(time(NULL));
    printf("choisier le theme\n");
    printf("1. Choufli Hal\n");
    printf("2. Labsa Tounsiya\n");
    printf("3. Mekla Tounsiya\n");
    printf("Votre choix : ");
    scanf("%d",&theme );

    FILE *fichierTheme = fopen(choisirThemeFichier(theme), "r");

    if (fichierTheme == NULL) {
        printf("Erreur lors de l'ouverture du fichier de thème.\n");
        return 1;
    }

        int scoreJoueur1 = 0;
        int scoreJoueur2 = 0;

        printf("Choisissez le mode (0 pour administrateur, 1 pour jouer seul, 2 pour jouer à deux, -1 pour quitter) : ");
        int mode;
        scanf("%d", &mode);

        if (mode == -1) {
            break;
        }

        if (mode == 0) {
            admin(fichierTheme);
        } else if (mode == 1) {
            jouerSolo(fichierTheme, &scoreJoueur1,theme);
        } else if (mode == 2) {
            jouerDeuxJoueurs(fichierTheme, &scoreJoueur1, &scoreJoueur2,theme);

}

    } while (mode != -1);

    return 0;
}
