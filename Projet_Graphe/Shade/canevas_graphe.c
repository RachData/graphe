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
			//printf("%d ",G.matrice_adjacence[i][j]);
			if(G.matrice_adjacence[i][j]) printf("%d ",j);
		}
		printf("\n");
	}
	
}

int degre(graphe G, int i){
	int voisin = 0;
	int k = 0;
	
	for (k = 0; k < G.nombre_sommet; k++){
		if( G.matrice_adjacence[i][k]) voisin ++;
	}
	
	return voisin;
}


graphe init_graphe(int n){//créé un graphe dont tous les sommets sont isolés
	graphe G; 
	G.nombre_sommet = n;
	G.matrice_adjacence = malloc(sizeof(*G.matrice_adjacence)*G.nombre_sommet);
	int i, j;
	for (i = 0; i < G.nombre_sommet; i++)
		G.matrice_adjacence[i] = malloc(sizeof(**G.matrice_adjacence) * G.nombre_sommet);
		
	for(i = 0; i< G.nombre_sommet; i++){
		for(j = 0; j< G.nombre_sommet; j++){
			G.matrice_adjacence[i][j] = 0;
		}
	}

	return G;
}

void libere_graphe(graphe G){
	int i;
	for (i = 0; i < G.nombre_sommet; i++)
		free(G.matrice_adjacence[i]);
		
	free(G.matrice_adjacence);

}

graphe cycle_graphe(int n){//créé un cycle
	graphe G;
	
	G.nombre_sommet = n;
	G.matrice_adjacence = malloc(sizeof(*G.matrice_adjacence)*n);
	int i;
	for (i = 0; i < n; i++)
		G.matrice_adjacence[i] = malloc(sizeof(**G.matrice_adjacence) * n);
		
	for(i = 0; i<n; i++){
		if (i == n-1) G.matrice_adjacence[i][0] = 1;
		else G.matrice_adjacence[i][i+1] = 1;
		
	}
	
	return G;
}


graphe complet_graphe(int n){//créé un graphe complet
	graphe G; 
	G.nombre_sommet = n;
	G.matrice_adjacence = malloc(sizeof(*G.matrice_adjacence)*n);
	int i, j;
	for (i = 0; i < n; i++)
		G.matrice_adjacence[i] = malloc(sizeof(**G.matrice_adjacence) * n);
		
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			G.matrice_adjacence[i][j] = 0;
			if(i != j ) G.matrice_adjacence[i][j] = 1;
		}
	}
	
	return G;
}


graphe alea_graphe(int n, float p){
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence = malloc(sizeof(*G.matrice_adjacence)*n);
	int i, j;
	int nb_voisins=rand()%n+1;
	int sommet=(rand()%(n-1))+1;
	
	for (i = 0; i < n; i++)
		G.matrice_adjacence[i] = malloc(sizeof(**G.matrice_adjacence) * n);
	
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			G.matrice_adjacence[i][j] = 0;
		}
	}
	
	for(i = 0; i<n; i++){
		for(j = 0; j<nb_voisins; j++){
			if(i != sommet ) G.matrice_adjacence[i][sommet] = 1;
			sommet=(rand()%(n-1))+1;
		}
		nb_voisins=(rand()%(n-1))+1;
	}
	return G;
}

graphe graphe_arbre(int *pere, int n){//créer un arbre couvrant à partir du tableau des pères représenté comme un graphe
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence = malloc(sizeof(*G.matrice_adjacence)*n);
	int i, j;
	for (i = 0; i < n; i++)
		G.matrice_adjacence[i] = malloc(sizeof(**G.matrice_adjacence) * n);
		
	for(i = 0; i<n; i++)
		for(j = 0; j<n; j++)
			G.matrice_adjacence[i][j] = 0;
	
	for(i = 0; i<n; i++) 
		if(pere[i]) G.matrice_adjacence[pere[i]][i] = 1;

	
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
	srand(time(NULL));
	int s = 2;
	graphe a = init_graphe(5);
	affiche_graphe(a);
	printf("Degré du %d = %d \n",s,degre(a,s));
	a = complet_graphe(5);
	affiche_graphe(a);
	printf("Degré du %d = %d \n",s,degre(a,s));
	a = cycle_graphe(5);
	affiche_graphe(a);
	printf("Degré du %d = %d \n",s,degre(a,s));
	
	int i;
	//a.nombre_sommet = 5;
	//int pere[a.nombre_sommet]= {2,4,3,0,3};
	int pere[5]= {2,4,3,0,3};
	for(i =0; i<5; i++) printf("%d \t", pere[i]);
	printf("\n");
	graphe b = graphe_arbre(pere,5);
	affiche_graphe(b);
	printf("Degré du %d = %d \n",s,degre(b,s));
	graphe L = alea_graphe(10,0.2);
	affiche_graphe(L);
	
	libere_graphe(a);
  	/*graphe G = cycle_graphe(10);
  	affiche_graphe(G);
	graphe H = complet_graphe(5);
	affiche_graphe(H);
	graphe L = alea_graphe(10,0.2);
	affiche_graphe(L);
	//graphe A = 
	//parcours_graphe(graphe A);
	//affiche_graphe(A);
	cycle_eulerien(L);
	cycle_eulerien(H);
	libere_graphe(G);
	libere_graphe(H);
	libere_graphe(L);
	//libere_graphe(A);
	* */
}
