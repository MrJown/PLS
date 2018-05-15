#include <stdio.h>
#include <stdlib.h>

#include "lecture_traitement_fichier.h"


/* Ouverture du fichier */
int* ouverture_fichier(char* nom_fichier) {


  int *occurence = malloc(sizeof(int)*128); // Allocation de 128*sizeof(int) octets dans la mémoire pour stocker le tableau

  /* Initialisation du tableau à 0 */
  for (int i = 0; i<128; i++) {
    occurence[i] = 0;
  }


  FILE* fichier = NULL;
  fichier = fopen(nom_fichier, "r+");

  // Si fopen n'a pas réussi à ouvrir le fichier
  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier %s\nIl n'existe peut être pas\n", nom_fichier);
    exit(0); // Quitte le programme
  }

  // Si le fichier est bien ouvert
  else {
    int caractere_actuel = 0;
    while (1) { // Boucle infinie
      caractere_actuel = fgetc(fichier); // Lecture du fichier caractere par caractere
      if (caractere_actuel == EOF) { break; } // Si le caracètre vaut EOF, on sort de la boucle
      occurence[caractere_actuel]++; // Incrémentation à la bonne case
      //printf("char ASCII : %c %d occurence : %d\n", caractere_actuel, caractere_actuel, occurence[caractere_actuel]);
    }
  }
  fclose(fichier); // Fermeture du fichier après utilisation

  return occurence;
}

/* Tester le programme
int main(int argc, char *argv[])

{
    int *test = ouverture_fichier("test.txt");
    return 0;
}
*/
