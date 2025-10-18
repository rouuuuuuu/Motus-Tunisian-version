#ifndef COULEUR_H
#define COULEUR_H
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
void afficherResultat(const char *motJoueur, const char *motSecret) {//la fonction afficherResultats a comme arguments deux tableau motJoueur et motSecret
    int LONGUEUR_MOT = strlen(motSecret);//la constante LONGUEUR_MOT est la taille de motSecret
    int k=0;//initialisation de compteur k qui va calculer le nombre d'occurence de chaque lettre
    for (int i = 0; i < LONGUEUR_MOT; i++) {//boucle pour verification
        if (motJoueur[i] == motSecret[i]) {//si la lettre i de mot joueur est la meme de mot secret
            printf(ANSI_COLOR_GREEN "%c " ANSI_COLOR_RESET, motJoueur[i]);//la lettre est correcte elle se colore en vert
            }
        else if (strchr(motSecret, motJoueur[i])) {//sinon si la lettre existe mais pas aca correcte place
            k++;//le compteur d'occurence ajoute +1
            if(k>1){//si k est superieur a 1
            printf(ANSI_COLOR_BLUE "%c " ANSI_COLOR_RESET, motJoueur[i]);}//la lettre se colore en bleu
            else if((k=1) &&( motJoueur[i] == motSecret[i])){//sinon si elle se repete qu'une seule fois et cette fois elle est correcte
               printf(ANSI_COLOR_GREEN "%c " ANSI_COLOR_RESET, motJoueur[i]);//elle se colore en vert
            }
            else if ((k=1)&&(motJoueur[i] != motSecret[i])) {//sinon si la lettre existe une fois et elle a deja pris sa correcte place
            printf(ANSI_COLOR_RED "%c " ANSI_COLOR_RESET, motJoueur[i]);//elle se colore cette fois en rouge
           }
            else {//sinon si elle existe une fois mais pas a sa place
            printf(ANSI_COLOR_BLUE "%c " ANSI_COLOR_RESET, motJoueur[i]);//elle se colore en bleu
            }
            }
        else {//on sort de la boucle if:elle n'existe meme pas dans mot secret
            printf(ANSI_COLOR_RED "%c " ANSI_COLOR_RESET, motJoueur[i]);//sinon elle se colore en rouge
    }
    }printf("\n");//retour a la ligne

}
#endif
