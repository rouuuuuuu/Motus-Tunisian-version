#ifndef ADMIN_H
#define ADMIN_H
void admin(FILE *fichier) {
    int n;
    int reglage;
    printf("choisir 0 pour ajouter ou 1 pour supprimer : ");
    scanf("%d", &reglage);
    if (reglage == 0) {
        printf("Combien de mots souhaitez-vous ajouter ? : ");
        scanf("%d", &n);

        fichier = fopen("my_file.txt", "a");
        for (int h = 0; h < n; h++) {
            char motAdmin[10];
            printf("Mode administrateur - Ajouter un mot : ");
            scanf("%s", motAdmin);
            fprintf(fichier, "%s\n", motAdmin);
        }

        fclose(fichier);
        printf("Mots ajoutés avec succès.\n");
    } else if (reglage == 1) {
        printf("Liste des mots existants :\n");
        char motLecture[50];
        rewind(fichier);

        while (fscanf(fichier, "%s", motLecture) != EOF) {
            printf("%s\n", motLecture);
        }
        printf("Entrez le mot que vous souhaitez supprimer : ");
        char motASupprimer[50];
        scanf("%s", motASupprimer);
        FILE *fichierTemp = fopen("my_file_temp.txt", "w");
        if (fichierTemp != NULL) {
            rewind(fichier);
            while (fscanf(fichier, "%s", motLecture) != EOF) {
                if (strcmp(motLecture, motASupprimer) != 0) {
                    fprintf(fichierTemp, "%s\n", motLecture);
                }
            }
            fclose(fichier);
            fclose(fichierTemp);
            remove("my_file.txt");
            rename("my_file_temp.txt", "my_file.txt");
            printf("Mot supprimé avec succès.\n");
        }
    }
}
#endif
