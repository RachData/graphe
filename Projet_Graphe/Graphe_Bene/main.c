#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct { //graphe représenté par une matrice d'adjacence
  	int nombre_sommet;
  	int ** matrice_adjacence;
} graphe;


void affiche_graphe(graphe G){
	int i,j;
	printf("Graphe avec %d sommets \n",G.nombre_sommet);
	for(i = 0; i<G.nombre_sommet; i++){
		printf("Voisins de %d: ",i);
		for(j = 0; j < G.nombre_sommet; j++){
			//if(G.matrice_adjacence[i][j]) printf("%d ",j);
			printf("%d ",G.matrice_adjacence[i][j]);
		}
		printf("\n");
	}
}

int degre(graphe G, int i){
    int degreSommet=0;
    int nbr_S;
    for ( nbr_S=0; nbr_S<G.nombre_sommet;nbr_S++){
    if(G.matrice_adjacence[i][nbr_S]==1){
        degreSommet=degreSommet+1;
    }
    }
    printf("le degre du sommet est: %d", degreSommet);
	return degreSommet;
}


graphe init_graphe(int n){//créé un graphe dont tous les sommets sont isolés
	graphe G;
	G.nombre_sommet=n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	  for (i=0;i<n;i++){
        G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	  }
	  int j=0;
	  for (i=0;i<n;i++){
        for (j=0;j<n;j++)
        {
            G.matrice_adjacence[i][j]=0;
        }
	  }
	return G;
}

void libere_graphe(graphe G){
    int i;
    for (i=0;i<G.nombre_sommet;i++){
    free(G.matrice_adjacence[i]);
    G.matrice_adjacence[i]=NULL;
        }
    free(G.matrice_adjacence);
    G.matrice_adjacence=NULL;
}

graphe cycle_graphe(int n){//créé un cycle
	graphe G;
	G.nombre_sommet=n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	  for (i=0;i<n;i++){
        G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	  }
	  int j=0;
	  for (i=0;i<n;i++){
        for (j=0;j<n;j++)
        {
             G.matrice_adjacence[i][j]=0;
        }
	}
	for (i=0;i<n;i++){
        if(i==n-1){
        G.matrice_adjacence[i][0]=1;
        }

        G.matrice_adjacence[i][i+1]=1;
	}
return G;
}

graphe complet_graphe(int n){//créé un graphe complet
	graphe G;
	G.nombre_sommet=n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	  for (i=0;i<n;i++){
        G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	  }
	  int j=0;
	  for (i=0;i<n;i++){
        for (j=0;j<n;j++)
        {
             G.matrice_adjacence[i][j]=0;
            if(i!=j){
                G.matrice_adjacence[i][j]=1;
            }

        }
	  }
	return G;
}


graphe alea_graphe(int n, float p){
	graphe G;
	return G;
}

graphe graphe_arbre(int *pere, int n){//créer un arbre couvrant à partir du tableau des pères représenté comme un graphe
	graphe G;
	G.nombre_sommet=n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	  for (i=0;i<n;i++){
        G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	  }
	  int j=0;
	  for (i=0;i<n;i++){
        for (j=0;j<n;j++)
        {
            G.matrice_adjacence[i][j]=0;
        }
	  }

	  for (i=0;i<n;i++){
	  if(pere[i] !=0 ){
        G.matrice_adjacence [pere[i]][i]=1;
	  }
	  }
	return G;
}



void parcours_sommet(graphe G, int s, int *couleur, int *pere){
}

void parcours_graphe(graphe G){
	int *couleur = calloc(G.nombre_sommet,sizeof(int)); // 0 est blanc, 1 gris et 2 noir
	int *pere = malloc(sizeof(int)*G.nombre_sommet);
	free(couleur);
	free(pere);
}



void cycle_eulerien(graphe G){//on suppose le graphe connexe
}


int main(){
	/* Tests pour vérifier si vos implémentations sont correctes*/
	/*srand(time(NULL));
  	graphe G = cycle_graphe(10);
  	affiche_graphe(G);
	graphe H = complet_graphe(5);
	affiche_graphe(H);
	graphe L = alea_graphe(10,0.2);
	affiche_graphe(L);
	graphe A = parcours_graphe(L);
	affiche_graphe(A);
	cycle_eulerien(L);
	cycle_eulerien(H);
	libere_graphe(G);
	libere_graphe(H);
	libere_graphe(L);
	libere_graphe(A);*/
	int i;
	int tabPere[5]={2,4,3,0,3};
	for (i=0;i<5;i++){
        printf("%d \t",tabPere[i] );
	}
    printf("\n");
    graphe b=graphe_arbre(tabPere, 5);
     affiche_graphe(b);

    /*graphe M=init_graphe(5);
    affiche_graphe(M);
    M=cycle_graphe(3);
    affiche_graphe(M);*/
    /*degre(M,1);*/

   //graphe M=complet_graphe(5);
    /*M=cycle_graphe(3);
    affiche_graphe(M);*/

    /*graphe S=complet_graphe(2);
    affiche_graphe(S);
    degre(S, 2);*/
}
