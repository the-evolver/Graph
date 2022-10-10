#include <iostream>
#include <list>
using namespace std;

class Graph {

public:
	list<pair<int, int>> edges;
	int V;

	Graph(int v) {
		this->V = v;
	}

	void addEdges(int v1 , int v2) {

		edges.push_back({v1, v2});
	}

	int find_set(int x , int parent[]) {
		if (parent[x] == -1)
			return x;


		return find_set(parent[x], parent);

	}

	void union_set(int a , int b, int parent[]) {

		int s1 = find_set(a, parent);
		int s2 = find_set(b, parent);

		if (s1 != s2) {
			parent[s2] = s1;
		}

	}


	bool cycle_detection() {

		int* parent = new int[V + 1];
		for (int i = 0 ; i <= V ; i++)
			parent[i] = -1;

		for (auto i : edges) {

			int v1 = i.first;
			int v2 = i.second;

			int s1 = find_set(v1, parent);
			int s2 = find_set(v2, parent);
			if (s1 == s2) {
				cout << " Warning ! Cycle is present in the graph .\n";
				return true;
			}
			else {
				union_set(v1, v2, parent);
			}

		}

		return false;
	}



};


int main() {

	Graph g(4);
	g.addEdges(1, 2);
	g.addEdges(3, 4);
	g.addEdges(1, 4);
	g.addEdges(2, 2);

	g.cycle_detection();





}

