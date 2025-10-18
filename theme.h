#ifndef theme_h
#define theme_h
const char *choisirThemeFichier(int theme) {
    switch (theme) {
        case 1:
            return "theme_choufli_hal.txt" ;
        case 2:
            return "theme_labsa_tounsiya.txt" ;
        case 3:
            return "theme_mekla_tounsiya.txt" ;
        default:
            return "my_file.txt";
    }
}
#endif

