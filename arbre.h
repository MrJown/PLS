
typedef struct a {
  char symbole;
  struct a *fgauche, *fdroite;
  char * codage;
} noeud;

/* type Arbre, pointeur vers un noeud */

typedef noeud *Arbre;
