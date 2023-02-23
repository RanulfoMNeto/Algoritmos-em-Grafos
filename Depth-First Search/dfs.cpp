#include <iostream>
#include <vector>

using namespace std;

// cores dos vertices
#define BRANCO -1 // vertice nao descoberto
#define CINZA 0 // vertice descoberto
#define PRETO 1 // vertice fechado

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii; // vetor de vetor de pares

void dfsVisit(vvii &LA, int u, vi &cor) {
    cor[u] = CINZA; // vértice branco u acabou de ser descoberto
    for (int i = 0; i < LA[u].size(); i++) { // explorar aresta (u,v)
        int v = LA[u][i].first;
        if (cor[v] == BRANCO) {
            dfsVisit(LA, v, cor);
        }
    }
    cor[u] = PRETO; // pintar u de preto; está terminado
}

void dfs(vvii &LA) {

    int n = LA.size();
    vi cor = vi(n, BRANCO);

    for (int u = 0; u < LA.size(); u++) {
        if (cor[u] == BRANCO) {
            dfsVisit(LA, u, cor);
        }
    }
}

int main() {
	int n; // quantidade de vértices
	int m; // quantidade de arestas

	cin >> n >> m;

	vvii LA = vvii(n, vii()); // lista de adjacência do grafo

	for(int k = 0; k < m; k++) {		
		int u, v, w; // aresta saindo do vértice u e alcançando v com peso w
		cin >> u >> v >> w;
		LA[u].push_back(ii(v, w));
	}

    dfs(LA);
	
	return 0;
}
