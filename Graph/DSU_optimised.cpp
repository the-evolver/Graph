#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {

public:
	int V;
	list<pair<int, int>> edges;

	Graph(int v) {
		this->V = v;

	}

	void addEdges(int v1 , int v2 ) {
		edges.push_back({v1, v2});
	}

	int find_set(int i , int* par) {

		if (par[i] == -1)
			return i;

		return par[i] = find_set(par[i], par);


	}

	void union_set(int i , int j , int* par, int* rank) {

		int f1 = find_set(j, par);
		int f2 = find_set(i, par);

		if (f1 != f2) {

			if (rank[f1] > rank[f2]) {
				par[f2] = f1;
				rank[f1] += rank[f2];
			} else {
				par[f1] = f2;
				rank[f2] += rank[f1];

			}


		}


	}

	bool cycle_detection() {

		int* parent = new int[V];
		int* rank = new int[V];

		for (int i = 0 ; i < V ; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}


		for (auto j : edges) {
			int j1 = j.first;
			int i1 = j.second;
			int f1 = find_set(j1, parent);
			int f2 = find_set(i1, parent);

			if (f1 == f2 ) {
				cout << " CYCLE ! FOUND \n";
				print(parent, rank); // just for understanding
				return 1;
			} else {

				union_set(j1, i1, parent, rank);
			}
		}

		cout << " Snoop ! No cycle Found \n";
		print( parent, rank); // just for understanding
		return 0;

	}

	void print(int* par , int * rank) {

		for (int i = 0 ; i < V ; i++) {
			cout << par[i] << " ";
		}
		cout << endl;
		for (int i = 0 ; i < V ; i++) {
			cout << rank[i] << " ";
		}

		cout << endl;

	}


};



int main() {

	Graph g(7);
	g.addEdges(0, 1);
	g.addEdges(1, 2);
	g.addEdges(2, 3);
	g.addEdges(0, 4);
	g.addEdges(5, 6);
	g.addEdges(2, 5);
	g.addEdges(2, 6);

	cout << g.cycle_detection();
	return 0;
}