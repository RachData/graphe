package graphe;

import java.awt.List;
import java.io.File;
import java.util.LinkedList;
import java.util.Stack;

import javax.sound.midi.Soundbank;

/**
 *         <p>
 *         Classe permettant de construire et manipuler les graphes.
 */
public class Graphe {

    // ATTRIBUTS
    private final int n;            // Nombre de sommets du graphe
    private int[][] matrice;        // Matrice d'adjacence du graphe


    // CONSTRUCTEURS

    /**
     * Construit un graphe vide à {@code n} sommets.
     *
     * @param n nombre de sommets du graphe
     * @throws IllegalArgumentException si {@code n} est négatif ou nul
     */
    public Graphe(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("Erreur dans la construction du graphe. Le nombre de sommets doit être strictement positif.");
        }

        this.n = n;
        this.matrice = new int[n][n];
    }


    /**
     * Construit un graphe ayant comme matrice {@code matrice}.
     *
     * @param matrice d'adjacence du graphe
     */
    public Graphe(int[][] matrice) {
        this.n = matrice.length;
        this.matrice = matrice;
    }

    // METHODES

    /**
     * Renvoie le nombre de sommets du graphe.
     *
     * @return le nombre de sommets du graphe
     */
    public int getN() {
        return this.n;
    }


    /**
     * Renvoie la matrice d'adjacence du graphe.
     *
     * @return la matrice associée au graphe
     */
    public int[][] getMatrice() {
        return this.matrice;
    }


    /**
     * vérifie que le sommet {@code v} est un sommet valide du graphe
     *
     * @param v sommet du graphe à verifier
     * @throws IllegalArgumentException si le sommet n'est pas valide
     */
    void verifieSommet(int v) {
        if (v < 0 || v >= n)
            throw new IllegalArgumentException(String.format("Le sommet %d n'est pas valide", v));
    }


    /**
     * Ajoute l'arête dont les extrémités sont les sommets {@code i} et {@code j} au graphe
     *
     * @param i l'un des sommets de l'arête à ajouter au graphe
     * @param j l'autre sommet de l'arête à ajouter au graphe
     * @return true si l'arête a été ajoutée au graphe
     * @throws IllegalArgumentException si {@code i} ou {@code j} ne sont pas des sommets valides
     * @throws IllegalArgumentException si {@code i} = {@code j}
     */
    public boolean ajouteArete(int i, int j) {
        // TODO
    	for (int i1 = 0; i1 < matrice.length; i1++) {
			if(i1==i)
			{
				for (int j1 = 0; j1 < matrice.length; j1++) {
					if(j1==j)
					{
						matrice[i][j]++;  
					}
				}
			}
		}
    	
        return false;
    }


    /**
     * Supprime l'arête dont les extrémités sont les sommets {@code i} et {@code j} du graphe
     *
     * @param i l'une des extrémités de l'arête à supprimer au graphe
     * @param j l'autre sommet de l'arête à supprimer au graphe
     * @return true si l'arête a été supprimée du graphe
     * @throws IllegalArgumentException si {@code i} et {@code j} ne sont pas des sommets valides
     */
    public boolean supprimeArete(int i, int j) {
        // TODO
    	int compteur = 0;
    	for (int i1 = 0; i1 < matrice.length; i1++) {
			if(i1==i)
			{
				compteur++;
				for (int j1 = 0; j1 < matrice.length; j1++) {
					if(j1==j)
					{
						if(matrice[i][j]!=0)
						{
							matrice[i][j]--;  
						}
						else
						{
							System.out.println("Il n'ya pas d'arrête entre le sommet "+i+" et "+j);
						}
					}
				}
			}
			else
			{
				compteur=0;
			}
		}
    	if(compteur==0)
    	{
    		System.out.println("Ce sommet n'existe pas dans le graphe");
    	}
        return true;
    }


    /**
     * Renvoie vrai si les sommets {@code i} et {@code j} sont voisins
     *
     * @param i l'un des sommets à vérifier
     * @param j l'autre sommet à vérifier
     * @return vrai si les sommets {@code i} et {@code j} sont voisins
     * @throws IllegalArgumentException si {@code i} et {@code j} ne sont pas des sommets valides
     */
    public boolean sontVoisins(int i, int j) {
        // TODO
    	boolean bool = false;
    	for (int i1 = 0; i1 < matrice.length; i1++) {
			for (int j1 = 0; j1 < matrice.length; j1++) {
				if(matrice[i][j]==1)
				{
					bool = true;
				}
			}
		}
        return bool;
    }


    /**
     * Calcule le nombre de voisins du sommet {@code v}
     *
     * @param v sommet à évaluer
     * @return le degré de {@code v}
     * @throws IllegalArgumentException si {@code v} n'est pas un sommet valide
     */
    public int degre(int v) {
        // TODO
    	int degre = 0;
    	for (int i1 = 0; i1 < matrice.length; i1++) {
    		
    		for (int j1 = 0; j1 < matrice.length; j1++) {
				if(matrice [i1][j1]==1)
				{
					if(i1==v || j1==v)
					{
						degre++;
					}
				}
			}
    		
		}
    	//
        return degre;
    }


    /**
     * Calcule le degré maximum du graphe
     *
     * @return le degré maximum du graphe
     */
    public int maxDegre() {
        // TODO
    	int degreMAx = 0;
    	int degre = 0;
    	for (int i1 = 0; i1 < matrice.length; i1++) {
    		degre = degre(i1);
    		if(degre > degreMAx)
			{
				degreMAx = degre;
				//degre = 0;
			}
		}
    	System.out.println("Le degré Maximum du graphe est : "+degreMAx);
        return degreMAx;
    }


    /**
     * Renvoie le nombre d'arêtes du graphe
     *
     * @return le nombre d'arêtes du graphe
     */
    public int nbAretes() {
        // TODO
    	int nbArrete = 0;
    	for (int i1 = 0; i1 < matrice.length; i1++) {
			for (int j1 = 0; j1 < matrice.length; j1++) {
				if(matrice[i1][j1]==1)
				{
					nbArrete++;
				}
			}
		}
    	
        return nbArrete*2;
    }


    /**
     * Vérifie que la matrice est une matrice d'adjacence valide.
     *
     * @param mat la matrice à vérifier
     * @return vrai si la matrice mat peut être la matrice d'adjacence d'un graphe, faux sinon.
     */
    public static boolean estMatriceAdjacence(int[][] mat) {
        // TODO
        return false;
    }


    /**
     * Renvoie vrai si {@code v} est un sommet isolé du graphe
     *
     * @param v sommet à évaluer
     * @return vrai si {@code v} est un sommet isolé du graphe
     * @throws IllegalArgumentException si {@code v} n'est pas un sommet valide
     */
    public boolean estIsole(int v) {
        // TODO
        return false;
    }


    /**
     * Renvoie le complémentaire du graphe courant
     *
     * @return le complémentaire du graphe courant
     */
    public Graphe complementaire() {
        // TODO
        return null;
    }


    /**
     * Renvoie un graphe complet possédant {@code n} sommets.
     *
     * @param n nombre de sommets du graphe complet
     * @return un graphe complet possédant {@code n} sommets
     * @throws IllegalArgumentException si {@code n} n'est pas valide
     */
    public static Graphe grapheComplet(int n) {
        // TODO
        return null;
    }


    /**
     * Renvoie la matrice d'incidence du graphe
     *
     * @return la matrice d'incidence du graphe
     */
    public int[][] matriceIncidence() {
        // TODO
        return null;
    }

    /**
     * Affiche le graphe.
     */
    public void affiche() {

        System.out.print("  | ");
        for (int i1 = 0; i1 < matrice.length; i1++) {
            System.out.print(i1 + " ");
        }

        System.out.println();

        for (int i2 = 0; i2 < matrice.length; i2++) {
            System.out.print("---");
        }

        System.out.println();

        for (int i3 = 0; i3 < matrice.length; i3++) {
            System.out.print(i3 + " | ");
            for (int j = 0; j < matrice[0].length; j++) {
                System.out.print(matrice[i3][j] + " ");
            }
            System.out.println();
        }

        for (int i4 = 0; i4 < matrice.length; i4++) {
            System.out.print("---");
        }
        System.out.println();
    }
    
    public LinkedList<Integer> getVosins(int v)
    {
    	LinkedList<Integer> voisins = new LinkedList<Integer>();
    	for (int i = 0; i < matrice.length; i++) {
			if(matrice[v][i]==1)
			{
				voisins.push(i);
			}
		}
    	return voisins;
    }
    
    public String parcoursLargeur(Graphe g)
    {
    	LinkedList<Integer> file = new LinkedList<Integer>();
    	file.add(0);
    	int i =0;
    	int aux;
    	int marque[] = new int[g.getN()];
    	LinkedList<Integer> list = new LinkedList<Integer>();
    	LinkedList<Integer> visite = new LinkedList<Integer>();	
    	while(!file.isEmpty())
    	{
    		//System.out.println("file1 = "+file);
    		aux = file.pop();
    		visite.push(aux);
    		//System.out.println("file2 = "+file);
    		list.push(aux); //= aux;
    		for (int i1 = 0; i1 < g.getN(); i1++) {
    			if(!visite.contains(i1))
    			{
				if(sontVoisins(aux, i1))
				{
					if(!file.contains(aux))
					{
						//System.out.println(aux+" et "+i1+" sont voisins");
						file.addFirst(i1);
						visite.addFirst(i1);
						//file.push(i1);
					}
				}
    			}
			}
    	}
    	String parcourLargeur="";
    	for (int jq = 0; jq < list.size(); jq++) 
    	{
    		parcourLargeur += list.get(jq)+" ";
    	}
    	return parcourLargeur;
    }
    
    public boolean cycle()
    {
    	LinkedList<Integer> visite = new LinkedList<Integer>();
    	LinkedList<Integer> list = new LinkedList<Integer>();
    	int couranSommet;
    	Boolean bool = true;
    	list.push(0);
    	
    	while(!list.isEmpty())
    	{
    		couranSommet = list.pop();
    		for (int i = 0; i < getVosins(couranSommet).size(); i++) {
				if(!visite.contains(i) && !getVosins(couranSommet).contains(couranSommet))
				{
					list.push(i);
					
				}
				else
				{
					if(couranSommet==getVosins(couranSommet).get(i))
					{
						bool = false;
					}
				}
			}
    		visite.add(couranSommet);
    	}
    		//System.out.println("bool = "+bool);
    	return bool;
    }
    
    public static boolean grapheBipartie(Graphe g)
    {
    	LinkedList<Integer> parcours = new LinkedList<Integer>();
    	LinkedList<Integer> visite = new LinkedList<Integer>();
    	LinkedList<Integer> ensembleV1 = new LinkedList<Integer>();
    	LinkedList<Integer> ensembleV2 = new LinkedList<Integer>();
    	
    	int courant;
    	boolean resultat = false;
    	parcours.push(0);
    	
    	while(!parcours.isEmpty())
    	{
    		courant = parcours.pop();
    		//System.out.println("voisin de "+g.getVosins(courant).get(i));
    		if(!visite.contains(courant))
			{
    			visite.push(courant);
    			if(!ensembleV1.contains(courant))
    			{
    				if(ensembleV2.contains(courant))
    				{
    					
    				}
    				else
    				{
    					ensembleV1.push(courant);
    					for (int j = 0; j < g.getVosins(courant).size(); j++) {
							if(!ensembleV2.contains(g.getVosins(courant).get(j)))
							{
								ensembleV2.push(g.getVosins(courant).get(j));
								visite.push(g.getVosins(courant).get(j));
								parcours.push(j);
							}
							else
							{
								resultat = true;
							}
						}
    					//
    					//resultat = true;
    				}
    			}
			}
    		}
    	return resultat;
    }

    public static void main(String[] args) {
        // Vous pouvez tester vos fonctions ici.
        // Si besoin, rajoutez des tests.
        try {
            int n = 5;
           
            Graphe g = new Graphe(n);
            g.ajouteArete(1, 4);
            g.ajouteArete(0, 4);
            g.ajouteArete(3, 4);
            g.ajouteArete(2, 4);
            //g.ajouteArete(1, 2);
            //g.ajouteArete(4, 4);
            //g.ajouteArete(4, 1);
            //g.ajouteArete(4, 3);
            //g.ajouteArete(3, 2);
            //g.ajouteArete(3, 1);
            if(g.sontVoisins(3, 2))
            {
            	System.out.println("3 et 2 sont voisins");
            }
            else
            {
            	System.out.println("3 et 2 ne sont pas voisins");
            }
            g.sontVoisins(3, 2);
            System.out.println("La matrice d'adjacence du graphe est :");
            g.affiche();
            System.out.println("Le degré du sommet 4 est : "+g.degre(4));
            g.maxDegre();
            System.out.println("Le nombre d'arrêtes du graphe est : "+g.nbAretes());
            System.out.println("Le parcours en largeur est :"+g.parcoursLargeur(g));

            /*if(g.cycle())
            {
            	System.out.println("Le Graphe contient un cycle");
            }
            else
            {
            	System.out.println("Le Graphe ne contient pas de cycle");
            }*/
            
            if(grapheBipartie(g)==true)
            {
            	System.out.println("Le Graphe n'est pas Bipartie");
            }
            else
            {
            	System.out.println("Le Graphe est Bipartie");
            }
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

}