#ifndef duo_h
#define duo_h
#include <stdio.h>
#define NB_ESSAIS_MAX 4

void jouerDeuxJoueurs(FILE *fichier, int *scoreJoueur1, int *scoreJoueur2, int theme){

int nombreDeParties;
    printf("\n******************************************************************\n");

    printf("Combien de parties souhaitez-vous jouer à deux ? : ");
    scanf("%d", &nombreDeParties);
            rewind(fichier);


    for (int i = 0; i < nombreDeParties; i++) {
        int NbMot1 = 0;
        char mot1[10];
        while (fscanf(fichier, "%s", mot1) != EOF) {
            NbMot1++;
        }
        rewind(fichier);

        if (NbMot1 == 0) {
            fclose(fichier);
            fichier = fopen("my_file.txt", "a");
            if (fichier != NULL) {
                remplirFichierAvecMotsParDefaut(fichier);
                fclose(fichier);
            }
            fichier = fopen("my_file.txt", "r");
        }

        int niveau1;
        printf("Joueur , choisissez le niveau\n 0 pour facile\n 1 pour normal\n 2 pour difficile\n Votre choix: ");
        scanf("%d", &niveau1);

        int longueurMin1, longueurMax1;
        if (niveau1 == 0) {
            longueurMin1 = 3;
            longueurMax1 = 4;
        } else if (niveau1 == 1) {
            longueurMin1 = 5;
            longueurMax1 = 6;
        } else if (niveau1 == 2) {
            longueurMin1 = 7;
            longueurMax1 = 8;
        } else {
            printf("Choix de niveau non valide. Veuillez choisir 0 pour facile, 1 pour normal, ou 2 pour difficile.\n");
            return 0;
        }

        int motsFacile1 = 0, motsNormal1 = 0, motsDifficile1 = 0;

        rewind(fichier);

        while (fscanf(fichier, "%s", mot1) != EOF) {
            int motLength1 = strlen(mot1);

            if (motLength1 >= 3 && motLength1 <= 4) {
                motsFacile1++;
            } else if (motLength1 >= 5 && motLength1 <= 6) {
                motsNormal1++;
            } else if (motLength1 >= 7 && motLength1 <= 8) {
                motsDifficile1++;
            }
        }
        if (motsFacile1 == 0 || motsNormal1 == 0 || motsDifficile1 == 0) {
            printf("Le fichier ne contient pas suffisamment de mots de chaque niveau. L'administrateur doit ajouter des mots de chaque niveau.\n");
            return 0;
        }

        do {
            rewind(fichier);
            int indiceAleatoire1 = rand() % NbMot1;
            for (int i = 0; i <= indiceAleatoire1; i++) {
                fscanf(fichier, "%s", mot1);
            }
        } while (strlen(mot1) < longueurMin1 || strlen(mot1) > longueurMax1);

        char tab2_1[20];
        strcpy(tab2_1, mot1);
        int LONGUEUR_MOT1 = strlen(mot1);
        char *motSecret1 = tab2_1;
        int essais1 = 1;
        char lettreDevinee1[LONGUEUR_MOT1];
        memset(lettreDevinee1, 0, sizeof(lettreDevinee1));

                   printf("\n Joueur, voici le mot à deviner :%c",motSecret1[0] );
                for (int f = 1; f < LONGUEUR_MOT1; f++) {
                    printf("-");
                }


        while (1) {
                if (essais1 > NB_ESSAIS_MAX) {
                  printf("\nfin de jeux zouz khasrin :(!!!\n");

                  break;
                }
            char motJoueur1[10];
            printf("\nJoueur 1, entrez un mot de %d  : ", LONGUEUR_MOT1);
            scanf("%s", motJoueur1);

            if (strlen(motJoueur1) != LONGUEUR_MOT1) {
                printf("Le mot doit avoir %d lettres.\n", LONGUEUR_MOT1);
                continue;
            }

            essais1++;
            int lettresCorrectes1 = 0;

            for (int f = 0; f < LONGUEUR_MOT1; f++) {
                if (motJoueur1[f] == motSecret1[f]) {
                    lettreDevinee1[f] = motSecret1[f];
                    lettresCorrectes1++;
                }
            }

            afficherResultat(motJoueur1, motSecret1);

            if (lettresCorrectes1 == LONGUEUR_MOT1) {
                printf("Mabrouk 8) , Joueur 1 a deviné le mot en %d essais: %s\n", essais1, motSecret1);
                scoreJoueur1 += essais1;
                 supprimerMot(choisirThemeFichier(theme), motSecret1);
                printf("Score après la partie %d - Joueur 1 : %d\n", i + 1, 1000/essais1);
                break;
            } else {
                printf("\n ghaleet aweed\n");
                printf("Le mot ");
                for (int f = 0; f < LONGUEUR_MOT1; f++) {
                    if (lettreDevinee1[f] != '\0') {
                        printf("%c", lettreDevinee1[f]);
                    } else {
                        printf("-");
                    }
                }

            }
            int essais2=1;

             char motJoueur2[10];
            printf("\nJoueur 2, entrez un mot de %d  : ", LONGUEUR_MOT1);
            scanf("%s", motJoueur2);

            if (strlen(motJoueur2) != LONGUEUR_MOT1) {
                printf("Le mot doit avoir %d lettres.\n", LONGUEUR_MOT1);
                continue;
            }

            essais2++;
            int lettresCorrectes2 = 0;

            for (int f = 0; f < LONGUEUR_MOT1; f++) {
                if (motJoueur2[f] == motSecret1[f]) {
                    lettreDevinee1[f] = motSecret1[f];
                    lettresCorrectes2++;
                }
            }

            afficherResultat(motJoueur2, motSecret1);

          if (lettresCorrectes2 == LONGUEUR_MOT1) {
                printf("Mabrouk 8) , Joueur 2 a deviné le mot en %d essais: %s\n", essais2-1, motSecret1);
                scoreJoueur2 += essais2;
                supprimerMot(choisirThemeFichier(theme), motSecret1);
                printf("Score après la partie %d - Joueur 2 : %d\n", i + 1, 1000/(essais2-1));
                break;}
                else {
                printf("\n ghaleet aweed\n");
                printf("Le mot ");
                for (int f = 0; f < LONGUEUR_MOT1; f++) {
                    if (lettreDevinee1[f] != '\0') {
                        printf("%c", lettreDevinee1[f]);
                    } else {
                        printf("-");
                    }
                }

        }


        }
    }
            fclose(fichier);

}
#endif

