#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {

public:
	int V;
	list<int>* adj;

	Graph(int v) {

		this->V = v;
		adj = new list<int>[V];

	}

	void addEdges(int v1 , int v2) {

		adj[v1].push_back(v2);

	}

	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << " Parent : " << i << " child :-> ";
			for (int j : adj[i])
				cout << j << "  ";

			cout << endl;
		}


	}

	bool cycle_helper(int curr, int par, vector<bool>& vis , vector<bool>& in_current_path) {

		vis[curr] = true;
		in_current_path[curr] = true;

		for (int j : adj[curr]) {

			// if j is already present in current path means cycle is there
			if (in_current_path[j] == true)
				return true;

			if (vis[j] == true) // means j is already visited means already calculated and curent_path[j] == false means its not forming cycle so we dont need to calculate again
				continue;

			if (cycle_helper(j, curr, vis, in_current_path) == true)
				return true;

		}

		in_current_path[curr] = false; // removing from current_path
		return false;
	}

	void cycle_detection() {

		vector<bool> vis(V, false);
		vector<bool> in_current_path(V, false);

		for (int i = 0 ; i < V ; i++) {
			if (vis[i] == false && cycle_helper(i, -1, vis, in_current_path) == true) {
				cout << " Cycle Found in above directed graph ..\n";
				return;
			}
		}

		cout << " Hurray ! No cycle Found ...\n";
		return;

	}


};


int main() {


	Graph g(10);
	g.addEdges(8 , 7);
	g.addEdges(7 , 2);
	g.addEdges(2, 4);
	g.addEdges(4, 0);
	g.addEdges(0 , 6);
	g.addEdges(6 , 1);
	g.addEdges(1 , 3);
	g.addEdges(3 , 9);
	g.addEdges(9 , 5);
	g.addEdges(0 , 7);

	g.printAdjList();
	g.cycle_detection();


	return 0;

}