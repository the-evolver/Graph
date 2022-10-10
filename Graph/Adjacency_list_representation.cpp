#include <iostream>
#include <list>

using namespace std;

class Graph {

public:
	int V;
	list<int> *adj;

	Graph(int v) {
		V = v;
		adj = new list<int>[v];
	}

	void addEdges(int vertex1 , int vertex2 , bool undirectional = true) {
		adj[vertex1].push_back(vertex2);
		if (undirectional == true) {
			adj[vertex2].push_back(vertex1);
		}
	}

	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << i << " -->  ";
			for (int j : adj[i])
				cout << j << "  ";
			cout << endl;
		}
	}



};

int main() {

	Graph g(6);
	g.addEdges(0, 1);
	g.addEdges(0, 4);
	g.addEdges(2, 1);
	g.addEdges(3, 4);
	g.addEdges(4, 5);
	g.addEdges(2, 3);
	g.addEdges(3, 5);

	g.printAdjList();


}