#include <iostream>
using namespace std;


class Graph {


public:
	int V;
	list<int>* adj;

	Graph(int v) {
		V = v;
		adj = new list<int>[v];
	}

	void addEdges(int v1, int v2) {

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);

	}

	bool hasCycle() {

		// iterating for all values because graph can be disconnected .. re babu
		for (int curr = 0 ; curr < V ; curr++) {
			vector<bool> vis(V, false);
			if (dfs(curr, -1, vis) == true)
				return true;
		}


		return false;
	}

	bool dfs(int curr, int par, vector<bool>& vis) {

		vis[curr] = true;

		for (int j : adj[curr]) {
			if (j == par)
				continue;
			if (vis[j] == true)
				return true;

			if (dfs(j, curr, vis) == true)
				return true;

		}

		return false;

	}




};