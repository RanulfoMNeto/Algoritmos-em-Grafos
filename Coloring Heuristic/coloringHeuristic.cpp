#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

bool degreePriority(ii p1, ii p2) {
	return p1.second > p2.second;
}

class Graph {
	public:
		int n;
		int m;
		vvi adj;

		Graph(int n, int m) {
			this->n = n;
			this->m = m;
			adj = vvi(n, vi());
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
		}

		int degree(int u) {
			return adj[u].size();
		}

		vi sortNodesByDregree() {
			vii aux;
			for (int i = 0; i < adj.size(); i++) {
				aux.push_back(ii(i, degree(i))); // <id, degree>
			}
			sort(aux.begin(), aux.end(), degreePriority);
			vi L;
			for (int i = 0; i < aux.size(); i++) {
				int v = aux[i].first;
				L.push_back(v);
			}
			return L;
		}

		vi coloringHeuristic() {
			// Seja L uma lista de vértices ordenada de forma descendente pelo grau;
			vi L = sortNodesByDregree();
			
			// c ← 1;
			int c = 1;
			vi color(n, -1);
			
			// while L ≠ ∅ do
			while(!L.empty()) {
				// for all v ∈ L tal que v não é colorido do
				for (int i = 0; i < L.size(); i++) {
					bool colored = false;
					int v = L[i];
					for (int j = 0; j < adj[v].size(); j++) {
						int u = adj[v][j];
						colored = (color[u] == c)?true:false;
					}
					// if nenhum vértice adjacente a v foi colorido com c then
					if (!colored) {
						// Colora v com a color c;
						color[v] = c;
					}
				}
				for (int i = 0; i < L.size(); i++) {
					int v = L[i];
					if (color[v] != -1) {
						L.erase(L.begin()+i);
						i--;
					}
				}
				// c ← c + 1;
				c++;
			}
			return color;
		}
};

int main() {

	int n; // number of nodes
	int m; // number of edges

	cin >> n >> m;

	Graph graph(n, m);

	for(int i = 0; i < m; i++) {		
		int u, v;
		cin >> u >> v;
		// Undirected Graph
		graph.addEdge(u, v);
		graph.addEdge(v, u);
	}

	vi color = graph.coloringHeuristic();

	for (int i = 0; i < color.size(); i++) {
		cout << i << ":" << color[i] << endl;
	}
	
	return 0;
}
