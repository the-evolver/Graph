#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {

public:
	int V;
	list<int>* adj;

	Graph(int v) {

		V = v;
		adj = new list<int>[v];


	}

	void addEdges(int vertex1 , int vertex2 , bool undirectional = true) {

		adj[vertex1].push_back(vertex2);
		if (undirectional == true)
			adj[vertex2].push_back(vertex1);

	}

	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << i << " ---> ";
			for (int j : adj[i])
				cout << j << "  ";

			cout << endl;
		}

	}

	void dfs(int src) {

		vector<bool>vis(V, false);
		stack<int>st;
		st.push(src);
		vis[src] = true;

		while (st.size() > 0 ) {

			int tp = st.top();
			st.pop();
			cout << tp << " , ";
			for (int j  : adj[tp]) {
				if (vis[j] == false) {
					vis[j] = true;
					st.push(j);
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
	g.dfs(1);




}