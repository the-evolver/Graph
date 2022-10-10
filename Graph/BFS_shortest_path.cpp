#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;


class Graph {

public:
	int V;
	list<int>* adj;

	Graph(int v) {
		V   = v ;
		adj =  new list<int>[v];
	}

	void addEdges(int vertex1 , int vertex2 , bool undirectional = true) {
		adj[vertex1].push_back(vertex2);
		if (undirectional == true)
			adj[vertex2].push_back(vertex1);

	}
	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << i << " :- ";
			for (auto j : adj[i])
				cout << j << " , ";
			cout << endl;
		}

	}

	void BFS_shortest_dist(int src , int dest = -1) {

		queue<int>qu;
		qu.push(src);

		vector<int>dist(V, -1);
		vector<int>parent(V, -1);
		dist[src] = 0;
		parent[src] = src;

		while (qu.size() > 0 ) {
			int f = qu.front();
			qu.pop();
			for (int j : adj[f]) {
				if (dist[j] == -1) {
					parent[j] = f;
					dist[j] = dist[f] + 1;
					qu.push(j);
				}
			}

		}

		for (int i = 0 ; i < V ; i++)
			cout << i << " -> " << dist[i] << endl;

		// for path
		if (dest != -1) {
			int temp = dest;
			while (temp != src) {
				cout << temp << " -> ";
				temp = parent[temp];
			}
			cout << src << endl;
		}



	}



};

int main() {

	Graph g(7);
	g.addEdges(1, 2);
	g.addEdges(1, 0);
	g.addEdges(0, 4);
	g.addEdges(4, 3);
	g.addEdges(4, 5);
	g.addEdges(5, 6);
	g.addEdges(3, 5);
	g.addEdges(2, 3);
	//g.printAdjList();
	g.BFS_shortest_dist(1, 6);


}