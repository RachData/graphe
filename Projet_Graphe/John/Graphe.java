class Graphe {
boolean[ ][ ] m;
Graphe (int n) {
m = new boolean[n][n];
for (int i = 0; i < n; ++i)
for (int j = 0; j < n; ++j)
m[x][y] = false;
}
static void ajouterArc (Graphe g, int x, int y) { g.m[x][y] = true; }
//afficher les éléments d'un graphe
static Graphe lireGraphe () {
	
BufferedReader in = //idiosyncratie Java !
newBufferedReader(newInputStreamReader(System.in));
try {
String s = in.readLine(); int n = Integer.parseInt(s);
Graphe g = newGraphe (n);
while((s = in.readLine()) != null) {
StringTokenizer st = newStringTokenizer(s);
int x = Integer.parseInt(st.nextToken());
int y = Integer.parseInt(st.nextToken());
if (0 <= x && x < n && 0 <= y && y < n) {
ajouterArc(g, x, y);
ajouterArc(g, y, x);
}
}
return g;
} catch (IOException e) {
System.err.println(e); System.exit(1); return null;
} }


//Parcours en profondeur 

final static intBLANC = 0, GRIS = 1, NOIR = 2;
static int[ ] couleur;
static void visiter (Graphe g) {
int n = g.succ.length; couleur = new int[n];
for (int x = 0; x < n; ++x) couleur[x] = BLANC;
for (int x = 0; x < n; ++x)
if (couleur[x] == BLANC)
dfs(g, x);
}
static void dfs (Graphe g, int x) {
couleur[x] = GRIS;
Pour toutysuccesseur dexdansG
faire {
if (couleur[y] == BLANC)
dfs(g, y);
}
couleur[x] = NOIR;
}
/*BLANC=non traitée, NOIR=traitée,
GRIS=en cours de traitement*/


//parcours profondeur deuxième version
tatic int numOrdre;
static void visiter (Graphe g) {
int n = g.succ.length; int[ ] num = new int[n]; numOrdre = -1;
for (int x = 0; x < n; ++x) num[x] = -1;
for (int x = 0; x < n; ++x)
if (num[x] == -1)
dfs(g, x, num);
}
static void dfs (Graphe g, int x, int[ ] num) {
num[x] = ++numOrdre;
for (Liste ls = g.succ[x]; ls != null; ls = ls.suivant) {
int y = ls.val;
if (num[y] == -1)
dfs(g, y, num);
}
}



//Parcours en largeur

static void visiter (Graphe g) {
int n = g.succ.length; couleur = new int[n];
FIFO f = newFIFO (n);
for (int x = 0; x < n; ++x) couleur[x] = BLANC;
for (int x = 0; x < n; ++x)
if (couleur[x] == BLANC) {
FIFO.ajouter(f, x); couleur[x] = GRIS;
bfs (g, f);
} }
static void bfs (Graphe g, FIFO f) {
while( !f.vide() ) {
int x = FIFO.supprimer (f);
for (Liste ls = g.succ[x]; ls != null; ls = ls.suivant) {
int y = ls.val;
if (couleur[y] == BLANC) {
FIFO.ajouter(f, y); couleur[y] = GRIS;
}
couleur[x] = NOIR;
} } }
//Memes programmes itéeratifs : DFS=pile BFS=file


//On cherche un chemin de d à s.
static Liste chemin (Graphe g, int d, int s, int[ ] couleur) {
couleur[d] = GRIS;
if (d == s)
return new Liste (d, null);
for (Liste ls = g.succ[d]; ls != null; ls = ls.suivant) {
int x = ls.val;
if (num[x] == BLANC) {
Liste r = chemin (g, x, s);
if (r != null)
return new Liste (d, r);
}
}
return null;
}

}