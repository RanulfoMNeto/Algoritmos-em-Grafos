#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi; // vetor de inteiros
typedef vector<vi> vvi; // vetor de vetor de inteiros

void bfs(vvi &G, int s) {

	int N = G.size();
	vector<bool> visitados(N, false); // indica se um vértice já foi visitado
	queue<int> fila; // fila de vértices a serem visitados

	visitados[s] = true;
	
	// ENQUEUE(Q, s)
	fila.push(s); // enfileirar (inserir no final) o vértice s

	// while Q ≠ ∅
	while(!fila.empty()) {
		
		// u = DEQUEUE(Q)
		int u = fila.front();
		fila.pop(); // // desenfileirar (remover do início) o vértice

		for (int i = 0; i < G[u].size(); i++) { // percorre a lista de adjacência do vértice atual (u)

			int v = G[u][i];
			if (!visitados[v]) {
				visitados[v] = true;
				// ENQUEUE(Q, v)
				fila.push(v);
			}
		}
	}
	
}

int main() {
	int N; // quantidade de vértices
	int M; // quantidade de arestas

	cin >> N >> M;

	vvi G = vvi(N, vi()); // lista de adjacência do grafo não ponderado

	for(int k = 0; k < M; k++) {		
		int u, v;
		cin >> u >> v;
		// aresta saindo do vértice u e alcançando v
		G[u].push_back(v); // insere o vértice v na lista de adjacência do vértice u
	}

    int s; // ponto de partida (source)
    cin >> s;
    bfs(G, s);
	
	return 0;
}