#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi; // vetor de vetor de inteiros

// estimativa de limite superior para o peso de um caminho mínimo da fonte s a cada vértice
vi d;
// predecessores dos vértices
vi p;

int INFINITY = INT_MAX;

void INITIALIZE_SINGLE_SOURCE(vvi &AM, int s) {
	int n = AM.size();
	d.assign(n, INFINITY);
	p.assign(n, -1); // NIL = -1
	d[s] = 0;
}

void RELAX(int u, int v, vvi &AM) {
	if (d[v] > d[u] + AM[u][v]) {
		d[v] = d[u] + AM[u][v];
		p[v] = u;
	}
}

int EXTRACT_MIN(vi &Q) {
	int menor = INFINITY, u, j;
	for (int i = 0 ; i < Q.size(); i++) {
		int v = Q[i];
		if (d[v] < menor) {
			menor = d[v];
			u = v;
			j = i;
		}
	}
	Q.erase(Q.begin()+j);
	return u;
}

void dijkstra(vvi &AM, int s) {

	INITIALIZE_SINGLE_SOURCE(AM, s);
	vi S; // conjunto S de vértices cujos pesos finais de caminhos mínimos que partem da fonte s já foram determinados
	vi Q; // fila de prioridades mínimas
	for (int i = 0; i < AM.size(); i++) {
		Q.push_back(i);
	}
	while(!Q.empty()) {
		int u = EXTRACT_MIN(Q);
		S.push_back(u);
		for (int v = 0; v < AM[u].size(); v++) {
			if (AM[u][v] != INFINITY) {
				RELAX(u, v, AM);
			}
		}
	}
	
}

int main() {
	int n; // quantidade de vértices
	int m; // quantidade de arestas

	cin >> n >> m;

	vvi AM = vvi(n, vi(n, INFINITY)); // lista de adjacência do grafo

	for(int k = 0; k < m; k++) {		
		int u, v, w; // aresta saindo do vértice u e alcançando v com peso w
		cin >> u >> v >> w;
		AM[u][v] = w;
	}

    int s; // ponto de partida
    cin >> s;
    dijkstra(AM, s);
	for (int i = 0; i < d.size(); i++) {
		cout << s << " - " << i << ": " << d[i] << endl;
	}
	
	return 0;
}