#ifndef NIVEAU_H
#define NIVEAU_H

#include <stdio.h>

void choisirNiveau(FILE *fichier ,int *longueurMin, int *longueurMax){
int nombreDeParties;
            printf("Combien de parties souhaitez-vous jouer  ? : ");
            scanf("%d", &nombreDeParties);

            for (int i = 0; i < nombreDeParties; i++) {
                int NbMot = 0;
                char mot[10];
                while (fscanf(fichier, "%s", mot) != EOF) {
                    NbMot++;
                }
                rewind(fichier);

                if (NbMot == 0) {
                    fclose(fichier);
                    fichier = fopen("my_file.txt", "a");
                    if (fichier != NULL) {
                        remplirFichierAvecMotsParDefaut(fichier);
                        fclose(fichier);
                    }
                    fichier = fopen("my_file.txt", "r");
                }

                int niveau;
                scanf("%d", &niveau);

                int longueurMin, longueurMax;
                if (niveau == 0) {
                    longueurMin = 3;
                    longueurMax = 4;
                } else if (niveau == 1) {
                    longueurMin = 5;
                    longueurMax = 6;
                } else if (niveau == 2) {
                    longueurMin = 7;
                    longueurMax = 8;
                } else {
                    printf("Choix de niveau non valide. Veuillez choisir 0 pour facile, 1 pour normal, ou 2 pour difficile.\n");
                    return 0;
                }

                int motsFacile = 0, motsNormal = 0, motsDifficile = 0;

                rewind(fichier);

                while (fscanf(fichier, "%s", mot) != EOF) {
                    int motLength = strlen(mot);

                    if (motLength >= 3 && motLength <= 4) {
                        motsFacile++;
                    } else if (motLength >= 5 && motLength <= 6) {
                        motsNormal++;
                    } else if (motLength >= 7 && motLength <= 8) {
                        motsDifficile++;
                    }
                }
                if (motsFacile == 0 || motsNormal == 0 || motsDifficile == 0) {
                    printf("Le fichier ne contient pas suffisamment de mots de chaque niveau. L'administrateur doit ajouter des mots de chaque niveau.\n");
                    return 0;
                }
            }
}
#endif
