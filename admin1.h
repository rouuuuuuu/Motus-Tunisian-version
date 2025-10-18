#ifndef ADMIN1_H
#define ADMIN1_H
void admin1(FILE *fichier) {
    int n;

    printf("\n******************************************************************\n");

    printf("Administrateur, Ajoute des mots:\n ");


        printf("Combien de mots souhaitez-vous ajouter ? : ");
        scanf("%d", &n);

        fichier = fopen("", "a");
        for (int h = 0; h < n; h++) {
            char motAdmin[10];
            printf("Mode administrateur - Ajouter un mot : ");
            scanf("%s", motAdmin);
            fprintf(fichier, "%s\n", motAdmin);
        }

        fclose(fichier);
        printf("Mots ajoutés avec succès.\n");}
#endif
