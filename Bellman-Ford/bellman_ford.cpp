#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// shortest distances from source to all other vertices
vi d;
// previous of all vertices
vi p;

// number of vertices
int n;

int INFINITY = INT_MAX;

void INITIALIZE_SINGLE_SOURCE(vvii &AL, int s) {
	d.assign(n, INFINITY);
	p.assign(n, -1); // NIL = -1
	d[s] = 0;
}

void RELAX(int u, int j, vvii &AL) {
	int v = AL[u][j].first;
	if (d[v] > d[u] + AL[u][j].second) {
		d[v] = d[u] + AL[u][j].second;
		p[v] = u;
	}
}

bool BELLMAN_FORD(vvii &AL, int s) {

	INITIALIZE_SINGLE_SOURCE(AL, s);

	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < (int)AL[u].size(); j++) {
				RELAX(u, j, AL);
			}
		}
	}

	for(int u = 0; u < n; u++) {
		for(int j = 0; j < (int)AL[u].size(); j++) {
			// v: position of the node in the adjacency list
			if (d[AL[u][j].first] > d[u] + AL[u][j].second) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int m; // number of edges

	cin >> n >> m;

	vvii AL = vvii(n, vii()); // graph adjacency list

	for(int i = 0; i < m; i++) {		
		int u, v, w; // edge leaving vertex 'u' and reaching 'v' with weight w
		cin >> u >> v >> w;
		AL[u].push_back(ii(v, w));
	}

    int s; // source
    cin >> s;
    BELLMAN_FORD(AL, s);
	
	return 0;
}