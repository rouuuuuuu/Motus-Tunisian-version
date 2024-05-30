#include <stdio.h>
#include <string.h>

void separateur(const char* mot, char tab[]) {
    int n = strlen(mot);

    for (int i = 0; i < n; i++) {
        tab[i] = mot[i];
    }
}

void testeur(const char* word , const char* mot, int n){

char array[20];

separateur(mot,array);

 for (int i=0;i<n;i++){

        if (word[i]==array[i]){
            printf("la place de %c est correcte\n",array[i]);}

            else
                {printf("la place de %c est incorrecte\n",array[i]);}
}
}
int main() {

  char le_mot[20],word[20];
  char tabchar[20];
  int n,m;

    printf("le mot donner par le jeu est : ");
    scanf("%s",word);

    for (int i = 0; i< n ; i++) {
       printf("%c\t", tabchar[i]);
    }


do{

printf("donner un mot : ");
 scanf("%s",le_mot);
 n=strlen(le_mot);
 m=strlen(word);

if(m!=n){
   printf("reessayer!\n");
}
}
while(m!=n);

separateur(le_mot, tabchar);

for (int i = 0; i< n ; i++) {
    printf("%c\t", tabchar[i]);
    }

    printf("\n");

testeur(word ,le_mot, m);

}









