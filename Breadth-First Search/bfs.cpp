#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii; // vetor de vetor de pares

void bfs(vvii &LA, int origem) {

	int n = LA.size();
	vector<bool> visitados(n, false);
	queue<int> fila;

	visitados[origem] = true;
	fila.push(origem);

	while(!fila.empty()) {

		int u = fila.front();
		cout << u << ":";
		fila.pop();

		for (int i = 0; i < LA[u].size(); i++) {

			int v = LA[u][i].first;
			cout << v;
			if (visitados[v] == false) {
				cout << "]";
				visitados[v] = true;
				fila.push(v);
			}
			cout << ",";
		}
		cout << endl;
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

    int origem; // ponto de partida
    cin >> origem;
    bfs(LA, origem);
	
	return 0;
}