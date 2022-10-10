#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>

using namespace std;


class Graph {

public:
	int V;
	list<int>* adj;

	Graph(int v) {

		V = v;
		adj = new list<int>[V];

	}

	void addEdges(int v1 , int v2) {

		adj[v1].push_back(v2); // directed graph....


	}
	void printAdjList() {

		for (int i = 0 ; i < V ; i++) {
			cout << i << " ---> ";
			for (int j : adj[i])
				cout << j << " , ";

			cout << endl;
		}
		cout << endl;


	}
	void topological_sort_bfs() {

		cout << " Topological sorting using bfs : ";
		queue<int> qu;
		vector<int> indegree(V, 0);

		for (int i = 0 ; i < V ; i++) {
			for (int j : adj[i])
				indegree[j]++;
		}

		for (int i = 0 ; i < V ; i++) {
			if (indegree[i] == 0)
				qu.push(i);
		}

		while (qu.size() > 0) {

			int top = qu.front();
			qu.pop();

			cout << top << " ";
			for (int j : adj[top]) {
				indegree[j]--;
				if (indegree[j] == 0)
					qu.push(j);
			}

		}
		cout << endl;
		return;

	}

	void topological_sort_dfs() {
		cout << " Topological sorting using dfs : ";
		vector<int> indegree(V, 0);
		stack<int> st;

		for (int i = 0 ; i < V ; i++) {
			for (int j : adj[i])
				indegree[j]++;
		}


		for (int i = 0 ; i < V ; i++) {
			if (indegree[i] == 0)
				st.push(i);
		}

		while (st.size() > 0 ) {
			int front = st.top();
			st.pop();
			cout << front << " ";
			for (int j : adj[front]) {
				indegree[j]--;
				if (indegree[j] == 0)
					st.push(j);
			}

		}


		cout << endl;

	}

};


int main() {

	Graph g(6);
	g.addEdges(0, 2);
	g.addEdges(1, 2);
	g.addEdges(1, 4);
	g.addEdges(4, 5);
	g.addEdges(3, 5);
	g.addEdges(2, 3);

	g.printAdjList();
	g.topological_sort_bfs();
	g.topological_sort_dfs();





	return 0;
}