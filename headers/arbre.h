
typedef struct a {
  char symbole;
  struct a *fgauche, *fdroite;
  char * codage;
  int occ;
} noeud;

/* type Arbre, pointeur vers un noeud */

typedef noeud *Arbre;
