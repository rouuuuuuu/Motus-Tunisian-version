#ifndef ADMIN_H
#define ADMIN_H
void admin(FILE *fichier) {//la fonction admin a comme parametre le fichier de type FILE
    int n;
    int reglage;//reglage peut prendre soit 0 pour ajouter des mot soit 1 pour supprimer
    printf("\n******************************************************************\n");

    printf("choisir 0 pour ajouter ou 1 pour supprimer : ");//le choix de l'admin
    scanf("%d", &reglage);
    if (reglage == 0) {//si l'admin choisie d'ajouter des mots
        printf("Combien de mots souhaitez-vous ajouter ? : ");//l'admin a le choix de combien de mot il souhaite ajouter
        scanf("%d", &n);//n indique le nbre des mots

        fichier = fopen("my_file.txt", "a");//ouverture de fichier
        for (int h = 0; h < n; h++) {//la boucle d'ajout des n mots
            char motAdmin[10];//taille max des caractere dans le mot est 10
            printf("Mode administrateur - Ajouter un mot : ");//message de demande d'ajout
            scanf("%s", motAdmin);//lecture de mot
            fprintf(fichier, "%s\n", motAdmin);//ajout de mot dans le fichier (theme choisie au debut)
        }

        fclose(fichier);//fermeture de fichier
        printf("Mots ajoutés avec succès.\n");//message de success d'ajout
    } else if (reglage == 1) {//si l'adim veut supprimer des mots
        printf("Liste des mots existants :\n");//affichage de la liste des mots parmi lesquels il peut supprimer
        char motLecture[50];
        rewind(fichier);//retour a la premiere ligne du fichier

        while (fscanf(fichier, "%s", motLecture) != EOF) {//l'execution de la boucle while qui affiche les mots de la liste
                              printf("%s\n", motLecture);//jusqu'a la fin du fichier(EOF) printf("%s\n", motLecture)
        }

        printf("Entrez le mot que vous souhaitez supprimer : ");//message d'entrer des mots
        char motASupprimer[10];//declaration de variable motASupprimer
        scanf("%s", motASupprimer);
        FILE *fichierTemp = fopen("my_file_temp.txt", "w");//ouverture du fichier temporelle
        if (fichierTemp != NULL) {
            rewind(fichier);
            while (fscanf(fichier, "%s", motLecture) != EOF) {//lecture de fichier jusqu'a la fin
                if (strcmp(motLecture, motASupprimer) != 0) {//si le mot a supprimer existe dans la liste
                    fprintf(fichierTemp, "%s\n", motLecture);//copier le contenu du fichier sans le mots a supprimer dans fichier temp

                }
            }
            fclose(fichier);//fermer le fichier
            fclose(fichierTemp);//fermer le fichier temp
            remove("my_file.txt");//supprimer le fichier
            rename("my_file_temp.txt", "my_file.txt");//nommé le fichier temp le nom de notre fichier
            printf("Mot supprimé avec succès.\n");//message de success de suppression
        }
    }
}
#endif
