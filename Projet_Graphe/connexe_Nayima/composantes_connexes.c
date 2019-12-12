#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 10			/* nombre de noeuds du graphe */

typedef struct cellule			/* noeud et pointeur */
{	int numero;
	struct cellule *suivant;
} Cellule, *LISTE;

struct table				/* Pointeur vers un tableau d'entiers et taille du tableau */
					/* pour stocker et trier les predecesseurs d'un sommet */
{
   int tableau[TAILLE];
   int degre;
};

typedef struct table Table;

LISTE graphe[TAILLE];		/* graphe = tableau de listes des successeurs */
int post[TAILLE];			/* rang dans l'ordre postfixe */
int explore[TAILLE];			/* pour repere qu'un noeud a ete explore */
int compteur = 0;			/* compteur pour calcul de post */
Table liste_sommets;			/* pour placer la liste des sommets, par ordre de post */
LISTE graphe_inverse[TAILLE];	/* graphe inverse =  tableau de listes des predecesseurs */


/* Alloue un noeud sans initialiser */
Cellule *AlloueCellule()
{
  Cellule *cell = (Cellule *) malloc(sizeof(Cellule));
  return cell;
}

/* Cree un noeud en l'initialisant avec val. */
Cellule *CreeCellule(int cle)
{
  Cellule *n = AlloueCellule();
  n->numero = cle;
  n->suivant = NULL;
  return n;
}

/* initialisation de l'exploration */
void initialise_explore(void)
{
  int i;
  for(i=0; i<TAILLE; i++) explore[i] = 0;
}

/* initialisations des graphes*/
void initialise_graphes(void)
{
  int i;
  liste_sommets.degre = TAILLE;
  for(i=0; i<TAILLE; i++)
  {
    graphe[i] = NULL; graphe_inverse[i] = NULL; /* initialisations des graphes */
  }
}

void postordre(int s)			/* exploration en profondeur à partir d'un sommet et calcul de post */
{
  Cellule *c;
  if (explore[s] == 0)				/* si s est inexplore */
  {
    explore[s] = 1;				/* s devient explore */
    for(c = graphe[s]; (c != NULL); c = c->suivant)	/* parcourt la liste des fils */
       postordre(c->numero);
    post[s] = compteur++ ; liste_sommets.tableau[post[s]] = s;	/* calcule post le bon ordre dans
liste_sommet */
  }
}

void parcours()				/* parcours en profondeur de tout le graphe */
{
  int i;
  for(i=0;i<TAILLE;i++) postordre(i) ;
}

/* Cree a partir du graphe le graphe inverse, avec predecesseurs classes selon post decroissant */
void CreeGrapheInverse(void)
{
   int i, s, k;
   Cellule *c, *d;
   for(i=0;i<TAILLE;i++)					/* parcours des sommets */
   {
      s = liste_sommets.tableau[i];		/* s est le i-ieme sommet par post croissant */
      for(c = graphe[s]; (c != NULL) ; c = c->suivant)		/* parcours des successeurs */
      {								/* s est predecesseur de k */
         k = c->numero; d = CreeCellule(s);
         d->suivant = graphe_inverse[k]; graphe_inverse[k] = d;	/* s est ajoute dans la liste des
predecesseurs de k */
      }
   }
}

void profondeur_inverse(int s)			/* exploration en profondeur à partir d'un sommet dans l'ordre inverse de post qui est l'ordre dans lequel se trouvent ses predecesseurs*/
{
  Cellule *c;
  if (explore[s] == 0)				/* si s est inexplore */
  {
    explore[s] = 1;
    printf("%d ",s);				/* s devient explore */
    for(c = graphe_inverse[s]; (c != NULL); c = c->suivant)	/* parcourt la liste des fils */
      profondeur_inverse(c->numero);
  }
}

void composantes_fortement_connexes(void)
{
   int i,j;
   initialise_explore();		/* explore est mis a 0 */
   parcours();			/* premier parcours et calcul de post */
   CreeGrapheInverse();  /* le graphe inverse est cree */
   initialise_explore();		/* explore est mis a 0 */
   for(i=TAILLE - 1; i>=0; i--)	/* exploration en profondeur dans l'ordre donne par liste_sommets */
      if(explore[liste_sommets.tableau[i]] == 0)
      {
         printf("Composante fortement connexe : ");
         profondeur_inverse(liste_sommets.tableau[i]);
         printf("\n");
         printf("\n");
      }
}



/* Facilites pour creer un graphe... */
void CreeListeSuccesseurs(int k, char succ[]) /* cree la liste des successeurs d'un sommet */
{
  char *p, *liste, set[]=",";
  int val;
  Cellule *c, *d;
  liste = (char *)malloc(strlen(succ)+1);
  strcpy(liste, succ);
  val = atoi(strtok(liste, set));
  if(val >= 0)
  {
    c = CreeCellule(val);
    graphe[k] = c;
  }
  while((p = strtok(NULL, set)) != NULL)
  {
    val = atoi(p);
    if(val >= 0)
    {
      d = CreeCellule(val);
      c->suivant = d;
      c = d;
    }
  }
}

int main(void)
{
  initialise_graphes();
  CreeListeSuccesseurs(0, "1,2");
  CreeListeSuccesseurs(1, "5");
  CreeListeSuccesseurs(2, "3");
  CreeListeSuccesseurs(3, "1,4");
  CreeListeSuccesseurs(4, "2,7,9");
  CreeListeSuccesseurs(5, "3,6");
  CreeListeSuccesseurs(6, "8");
  CreeListeSuccesseurs(7, "6");
  CreeListeSuccesseurs(8, "7");
  CreeListeSuccesseurs(9, "8");
   composantes_fortement_connexes();

}

