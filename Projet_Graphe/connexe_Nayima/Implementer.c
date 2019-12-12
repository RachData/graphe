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
			//if(G.matrice_adjacence[i][j])
			//printf("%d ",j);
			printf("%d ",G.matrice_adjacence[i][j]);
		}
		printf("\n");
	}
}

void degre(graphe G, int i){
	int nbre_sommet=0;
	for(int k = 0; k<G.nombre_sommet; k++){

		if(G.matrice_adjacence[i][k]==1){
			nbre_sommet = nbre_sommet +1;
	}

	//return nbre_sommet;
}
    printf("son degre est : %d",nbre_sommet);
    //return nbre_sommet;
}

graphe init_graphe(int n){//créé un graphe dont tous les sommets sont isolés
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	for(i=0;i<n;i++)
	{
		G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G.matrice_adjacence[i][j]=0;
		}
	}
	return G;
}

graphe complet_graphe(int n){//créé un graphe complet
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	for(i=0;i<n;i++)
	{
		G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G.matrice_adjacence[i][j]=0;
			if(i!=j)
			{
				G.matrice_adjacence[i][j]=1;
			}
		}
	}
	return G;
}

graphe cycle_graphe(int n){//créé un cycle
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int i=0;
	for(i=0;i<n;i++)
	{
		G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	}
	int j;
	  for(j=0;j<n;j++)
        {
            if(j!=n-1)
            {
                G.matrice_adjacence[j][j+1]=1;
            }

            G.matrice_adjacence[n-1][0]=1;
        }

	return G;
}

void libere_graphe(graphe G){

    for(int i=0; i<G.nombre_sommet; i++ )
    {
        free(G.matrice_adjacence[i]);
    }
    free(G.matrice_adjacence);
}

graphe graphe_arbre(int *pere, int n){
	graphe G;
	G.nombre_sommet = n;
	G.matrice_adjacence=malloc(sizeof (*G.matrice_adjacence)*n);
	int val=0;
	for(int i=0;i<n;i++)
	{
		G.matrice_adjacence[i]=malloc(sizeof(**G.matrice_adjacence)*n);
	}
	for(int k=0;k<G.nombre_sommet;k++)
	{
        if(pere[k]!=-1)
        {
            val=pere[k];
            G.matrice_adjacence[val][k]=1;
        }

	}

    for(int l=0;l<G.nombre_sommet;l++)
    {
        for(int p=0; p<G.nombre_sommet;p++)
        {
            if(G.matrice_adjacence[l][p]!=1)
            {
                G.matrice_adjacence[l][p]=0;
            }
        }
    }
	return G;
}

int main(){
	/* Tests pour vérifier si vos implémentations sont correctes*/
    /*graphe g=init_graphe(4);
	affiche_graphe(g);
	printf("\n");
	graphe H = complet_graphe(5);
	affiche_graphe(H);
	printf("\n");
	degre(g, 2);
	printf("\n");

    graphe H = cycle_graphe(5);
    affiche_graphe(H);
    libere_graphe(H);*/

    int T[4]={-1,0,0,1};
    graphe g=graphe_arbre(T,4);
    affiche_graphe(g);

}
