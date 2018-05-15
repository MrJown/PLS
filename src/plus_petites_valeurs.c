#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//#include "arbre.h"
#include "lecture_traitement_fichier.h"
#include "plus_petites_valeurs.h"

int* deux_plus_petites_valeurs(int* tableau) {

  int i;
  int min = INT_MAX;
  int indice_min;
  int deux_min = INT_MAX;
  int deux_indice_min;

/* On récupère le plus petit entier du tableau */
  for (i = 0; i < 128; i++) {
    while (tableau[i] == 0 ) { i++; } // On saute tous les cas ou l'indice vaut 0
    // On place le nouveau minimum
    if (min > tableau[i]) {
      min = tableau[i];
      indice_min = i;
    }
  }

/* On cherche maintenant le deuxième plus petit entier du tableau */
  for (i = 0; i < 128; i++) {
    while (tableau[i] == 0) { i++; } // On saute tous les cas ou l'indice vaut 0
    if (deux_min >= tableau[i] && i != indice_min) { // Il ne faut pas que ce soit la même case qu'avant
      deux_min = tableau[i];
      deux_indice_min = i;
    }
  }

  /* Cas où le tableau est rempli de 0 */
  if (indice_min > 127 && deux_indice_min > 127) {
    indice_min = INT_MAX;
    deux_indice_min = INT_MAX;
  }

  if (deux_indice_min > 127) {
    deux_indice_min = INT_MAX;
  }

  /* On stocke les deux indices dans le tableau que l'on retourne*/
  int *indices = malloc(sizeof(int)*2); // Allocation de 2*sizeof(int) octets dans la mémoire pour stocker le tableau
  indices[0] = indice_min;
  indices[1] = deux_indice_min;
  return indices;
}







int* deux_petites_valeurs_noeud(noeud** tableau) {
  int min = INT_MAX;
  int indice_min;
  int deux_min = INT_MAX;
  int deux_indice_min;
  int i;
  noeud* p1 = malloc(sizeof(noeud));
  noeud* p2 = malloc(sizeof(noeud));

  /* On récupère le premier plus petit noeud du tableau */
for (i = 0; i < 128; i++) {
  while (tableau[i] == NULL && i < 128) { i++; } // On saute tous les cas ou l'indice vaut NULL
  if (i > 127) { break; } // Si i est plus grand que le dernier indice du tableau, on sort du for
  if (min > tableau[i]->occ) {
    indice_min = i;
    min = tableau[i]->occ;
  }
}
    printf("testmin %d indice : %d\n", min, indice_min);

  /* On cherche maintenant le deuxième plus petit noeud du tableau */
  for (i = 0; i < 128; i++) {
    while (tableau[i] == NULL && i < 128) { i++; } // On saute tous les cas ou l'indice vaut NULL
    if ( i > 127) { break; } // Si i est plus grand que le dernier indice du tableau, on sort du for
    if (deux_min >= tableau[i]->occ && i != indice_min) {
      deux_indice_min = i;
      deux_min = tableau[i]->occ;
    }
  }
    printf("testmin2 %d indice : %d\n", deux_min, deux_indice_min);

  /* Cas où le tableau est rempli de 0 */
  if (indice_min > 127 && deux_indice_min > 127) {
    indice_min = INT_MAX;
    deux_indice_min = INT_MAX;
  }

  /* On stocke les deux indices dans un tableau que l'on retourne */
  int* indices_noeuds_min = malloc(sizeof(int)*2);
  indices_noeuds_min[0] = indice_min;
  indices_noeuds_min[1] = deux_indice_min;
  return indices_noeuds_min;

  }

/*
int main(int argc, char *argv[])

{
// Test de la fonction deux_plus_petites_valeurs

    int * test = malloc(sizeof(int)*128);
    for (int i = 0; i < 128; i++) {
      test[i] = 0;
    }

  //  int* test = ouverture_fichier("test.txt");
    int* test2 = deux_plus_petites_valeurs(test);
     printf("%d %d\n", test2[0], test2[1]);

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





    return 0;
}
*/
