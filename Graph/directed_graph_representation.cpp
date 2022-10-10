// directed_graph_representation

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {

public:
	string name;

	list<string>nbrs;

	Node(string name) {
		this->name = name;
	}

};

class Graph {
public:
	unordered_map<string, Node*>up;

	Graph(vector<string> cities) {

		for (int i = 0 ; i < cities.size(); i++) {
			up[cities[i]] = new Node(cities[i]);
		}

	}

	void addEdges(string city1 , string city2 , bool undire = false) {

		up[city1]->nbrs.push_back(city2);

		if (undire == true) {
			up[city2]->nbrs.push_back(city1);
		}

	}

	void printList() {
		for (auto x : up) {
			cout << x.first << " --> ";

			for (auto i : x.second->nbrs) {
				cout << i << " ,";
			}
			cout << endl;
		}
	}


};


int main() {

	vector<string> cities = {"Delhi", "London", "Paris", "New York"};
	Graph g(cities);
	g.addEdges("Delhi", "London");
	g.addEdges("Delhi", "Paris");
	g.addEdges("Paris", "New York");
	g.addEdges("New York", "London");

	g.printList();


	return 0;
}