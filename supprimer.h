#ifndef supprimer_H
#define supprimer_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void supprimerMot(const char *nomFichier, const char *motASupprimer) {
    char motCourant[10]; // Variable pour stocker le mot actuellement lu du fichier
    char **motsTemp = NULL; // Pointeur vers un tableau de chaînes de caractères temporaire
    size_t nbMots = 0; // Nombre de mots actuellement stockés dans motsTemp

    FILE *fichier = fopen(nomFichier, "r"); // Ouvre le fichier en mode lecture
    if (fichier == NULL) { // Vérifie si l'ouverture du fichier a échoué
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return;
    }

    // Lecture des mots du fichier jusqu'à la fin
    while (fscanf(fichier, "%99s", motCourant) != EOF) { // Lit un mot du fichier
        if (strcmp(motCourant, motASupprimer) != 0) { // Vérifie si le mot lu n'est pas celui à supprimer
            motsTemp = realloc(motsTemp, (nbMots + 1) * sizeof(char *)); // Réalloue de la mémoire pour motsTemp
            motsTemp[nbMots] = strdup(motCourant); // Copie le mot lu dans motsTemp
            nbMots++; // Incrémente le nombre de mots stockés
        }
    }
    fclose(fichier); // Ferme le fichier après lecture

    fichier = fopen(nomFichier, "w"); // Réouvre le fichier en mode écriture
    if (fichier == NULL) { // Vérifie si l'ouverture du fichier a échoué
        printf("Erreur lors de la réouverture du fichier %s.\n", nomFichier);
        // Libération de la mémoire allouée pour motsTemp
        for (size_t i = 0; i < nbMots; i++) {
            free(motsTemp[i]);
        }
        free(motsTemp);
        return;
    }

    // Écriture des mots restants dans le fichier
    for (size_t i = 0; i < nbMots; i++) {
        fprintf(fichier, "%s\n", motsTemp[i]); // Écrit un mot dans le fichier
        free(motsTemp[i]); // Libère la mémoire allouée pour le mot actuel
    }
    free(motsTemp); // Libère la mémoire allouée pour motsTemp
    fclose(fichier); // Ferme le fichier après écriture
}
#endif
