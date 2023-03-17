#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

class Graph {
	public:
		int n;
		int m;
		vvi adj;

		Graph(int n, int m) {
			this->n = n;
			this->m = m;
			adj = vvi(n, vi(n, 0));
		}

		void addEdge(int u, int v, int w) {
			adj[u][v] = w;
		}
};

vi augmentingPath(vi parent, int s, int t) {
	vi path;
	while (s != t) {
		path.push_back(t);
		t = parent[t];
	}
	path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}

bool bfs(Graph &graph, int s, int t, vi &path) {
	vvi &LA = graph.adj;
	int n = graph.n;
	vector<bool> visited(n, false);
	queue<int> Q;

	visited[s] = true;
	Q.push(s);

	vi parent(n, -1);

	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int v = 0; v < LA[u].size(); v++) {
			if (visited[v] == false && graph.adj[u][v] > 0) {
				parent[v] = u;
				visited[v] = true;
				Q.push(v);
			}
		}
	}

	if (visited[t]) {
		path = augmentingPath(parent, s, t);
	}

	return visited[t];
}

int min(Graph residual, vi p) { // min {Cf(u, v) : (u, v) está em p}
	int residualCapacity = INT_MAX;
	for (int i = 0; i < p.size()-1; i++) {
		int u = p[i];
		int v = p[i+1];
		residualCapacity = min(residualCapacity, residual.adj[u][v]);
	}
	return residualCapacity;
}

int fordFulkerson(Graph graph, int s, int t) {
	Graph residual = graph;
	int maxFlow = 0;
	vi p; // Augmenting path p
	while(bfs(residual, s, t, p)) {
		// A quantidade máxima possível de aumento para o fluxo em cada aresta de um caminho aumentador p é denominada capacidade residual de p e é dada por:
		int residualCapacity = min(residual, p);

		for (int i = 0; i < p.size()-1; i++) {
			int u = p[i];
			int v = p[i+1];
			residual.adj[u][v] -= residualCapacity;
      		residual.adj[v][u] += residualCapacity;
		}
		maxFlow += residualCapacity;
	}
	return maxFlow;
}

int main() {

	int n; // number of nodes
	int m; // number of edges

	cin >> n >> m;

	Graph graph(n, m);

	for(int i = 0; i < m; i++) {		
		int u, v, w;
		cin >> u >> v >> w;
		// Directed Graph
		graph.addEdge(u, v, w);
	}
	int s, t;
	cin >> s >> t;
	cout << fordFulkerson(graph, s, t) << endl;
	
	return 0;
}
