#ifndef DEFAULT_H
#define DEFAULT_H
void remplirFichierAvecMotsParDefaut(FILE *fichier) {
    const char *motsFaciles[] = {
        "chat", "lune", "pain", "eau",
    };

    const char *motsNormaux[] = {
        "maison", "plage",
    };

    const char *motsDifficiles[] = {
        "architecte", "bureaux",
    };

    int nombreMotsFaciles = sizeof(motsFaciles) / sizeof(motsFaciles[0]);
    int nombreMotsNormaux = sizeof(motsNormaux) / sizeof(motsNormaux[0]);
    int nombreMotsDifficiles = sizeof(motsDifficiles) / sizeof(motsDifficiles[0]);

    for (int i = 0; i < nombreMotsFaciles; i++) {
        fprintf(fichier, "%s\n", motsFaciles[i]);
    }

    for (int i = 0; i < nombreMotsNormaux; i++) {
        fprintf(fichier, "%s\n", motsNormaux[i]);
    }

    for (int i = 0; i < nombreMotsDifficiles; i++) {
        fprintf(fichier, "%s\n", motsDifficiles[i]);
    }
}
#endif
