#ifndef SOLO_H
#define SOLO_H
#include <stdio.h>
#include "theme.h"
#include "admin1.h"
#define NB_ESSAIS_MAX 4
void jouerSolo(FILE *fichier, int *scoreJoueur1 , int theme){
int nombreDeParties;
            printf("\n******************************************************************\n");

            printf("Combien de parties souhaitez-vous jouer en solo ? : ");
            scanf("%d", &nombreDeParties);
            rewind(fichier);

            for (int i = 0; i < nombreDeParties; i++) {
                int NbMot = 0;
                char mot[10];
                while (fscanf(fichier, "%s", mot) != EOF) {
                    NbMot++;
                }
                rewind(fichier);

                if (NbMot == 0) {

                    fichier = fopen("my_file.txt", "a");
                    if (fichier != NULL) {
                        remplirFichierAvecMotsParDefaut(fichier);
                        fclose(fichier);
                    }
                    fichier = fopen("my_file.txt", "r");
                }

                int niveau;
        printf("Joueur , choisissez le niveau\n 0 pour facile\n 1 pour normal\n 2 pour difficile\n Votre choix: ");
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

                do {
                    rewind(fichier);
                    int indiceAleatoire = rand() % NbMot;
                    for (int i = 0; i <= indiceAleatoire; i++) {
                        fscanf(fichier, "%s", mot);
                    }
                } while (strlen(mot) < longueurMin || strlen(mot) > longueurMax);

                char tab2[50];
                strcpy(tab2, mot);
                int LONGUEUR_MOT = strlen(mot);
                char *motSecret = tab2;
                int essais = 0;
                char lettreDevinee[LONGUEUR_MOT];
                memset(lettreDevinee, 0, sizeof(lettreDevinee));

                printf("\nJoueur 1, voici le mot à deviner :%c",motSecret[0] );
                for (int f = 1; f < LONGUEUR_MOT; f++) {
                    printf("-");
                }

                while (1) {
                        if (essais+1 > NB_ESSAIS_MAX) {//si il atteint le nombre d'essais
                  printf("\n fin de jeux khsert :( !!!\n");//message qu'il a perdu

                  break;//break: fin de jeu pas besoin de continuer
                }
                    char motJoueur[LONGUEUR_MOT];
                    printf("\nJoueur 1, entrez un mot de %d  : ", LONGUEUR_MOT);
                    scanf("%s", motJoueur);

                    if (strlen(motJoueur) != LONGUEUR_MOT) {
                        printf("Le mot doit avoir %d lettres.\n", LONGUEUR_MOT);
                        continue;
                    }

                    essais++;
                    int lettresCorrectes = 0;

                    for (int f = 0; f < LONGUEUR_MOT; f++) {
                        if (motJoueur[f] == motSecret[f]) {
                            lettreDevinee[f] = motSecret[f];
                            lettresCorrectes++;
                        }
                    }

                    afficherResultat(motJoueur, motSecret);


                    if (lettresCorrectes == LONGUEUR_MOT) {
                        printf("Mabrouk 8) , Joueur tala3haaa baad %d mara: %s\n", essais, motSecret);
                        scoreJoueur1 += essais;
                       supprimerMot(choisirThemeFichier(theme), motSecret);
                        printf("Score après la partie %d - Joueur  : %d\n", i + 1, (1000/essais));

                       printf("\n******************************************************************\n");

                        break;
                    } else {
                        printf("\n ghaleet aweed\n");
                        printf("Le mot ");
                        for (int f = 0; f < LONGUEUR_MOT; f++) {
                            if (lettreDevinee[f] != '\0') {
                                printf("%c", lettreDevinee[f]);
                            } else {
                                printf("-");
                            }
                        }

                    }
                }



            }            fclose(fichier);

            }

            #endif
