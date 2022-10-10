#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {

public:
	int V;
	list<int>* adj;

	Graph(int v) {
		V = v;
		adj = new list<int>[v];

	}

	void addEdges(int edge1 , int edge2 , bool undire = true) {
		adj[edge1].push_back(edge2);
		if (undire == true)
			adj[edge2].push_back(edge1);

	}

	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << i << " : - : ";
			for (auto j : adj[i])
				cout << j << " , ";
			cout << endl;
		}



	}

	void bfs(int source) {

		queue<int> qu;

		qu.push(source);

		vector<bool>vis(V, false);
		vis[source] = true;
		while (qu.size() > 0) {
			int top = qu.front();
			qu.pop();
			cout << top << " ,";
			for (auto i : adj[top]) {
				if (vis[i] == false) {
					qu.push(i);
					vis[i] = true;
				}
			}


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

	g.printAdjList();
	g.bfs(1);



	return 0;



}