#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lecture_traitement_fichier.h"
#include "plus_petites_valeurs.h"

int main (int argc, char *argv[]) {

  // Test de la fonction deux_plus_petites_valeurs
  int compteur = 0;
//  int * test = malloc(sizeof(int)*128);
//  for (int i = 0; i < 128; i++) {
//    test[i] = 0;
//  }

  int* test = ouverture_fichier("test.txt", &compteur);
  int* test2 = deux_plus_petites_valeurs(test);
  // printf("%d %d %p\n", test2[0], test2[1], compteur);


/*
  // Test de la fonction deux_petites_valeurs_noeud

      noeud* test = malloc(sizeof(noeud));
      test->occ = 4;
      noeud* test2 = malloc(sizeof(noeud));
      test2->occ = 5;
      noeud* test3 = malloc(sizeof(noeud));
      test3->occ = 10;
      noeud* test4 = malloc(sizeof(noeud));
      test4->occ = 1;

      noeud** test6 = malloc(sizeof(noeud)*128);
        test6[0] = test;
        test6[1] = test2;
        test6[2] = test3;
        test6[3] = test4;

      int* test5 = deux_petites_valeurs_noeud(test6);
      printf("%d %d\n", test5[0], test5[1]);
*/
  return 0;
}
