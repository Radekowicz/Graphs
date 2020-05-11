#include "Kruskal.h"
#include "Queue.h"
#include "DSStruct.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <iostream>
#include<fstream>
#include<string>


using namespace std;

Kruskal::Kruskal() {

	AdjacencyMatrix matrix = AdjacencyMatrix();
	matrix.read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	matrix.print();
	cout << endl;


	Queue queue = Queue(matrix.edgeAmount);

	Edge edge;
	for (int i = 0; i < matrix.vertexAmount; ++i) {
		for (int j = 0; j < matrix.vertexAmount; ++j) {

			int edgeWeight = matrix.toQueue(i, j);
			edge = Edge(i, j, edgeWeight);

			if (edgeWeight != 0 && !queue.edgeExists(Edge(j, i, edgeWeight))) {
				queue.push(edge);
				edge.toString();
			}

		}
	}


	cout << endl << endl;

	queue.print();

	cout << endl;

	for (int i = 0; i < matrix.edgeAmount; ++i) {
		queue.getFirstEdge().toString();
		queue.pop();
	}


}

void Kruskal::read(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	string word;

	stream >> word;
	int vertexAmount = std::stoi(word);
	cout << "Vertex amount: " << vertexAmount << endl;


	stream >> word;
	int edgeAmount = std::stoi(word);
	cout << "Edge amount: " << edgeAmount << endl;

	queue = Queue(edgeAmount);

	int loop = std::stoi(word);
	int v1, v2, weight;
	for (int i = 0; i < loop; ++i) {
		stream >> word;
		v1 = std::stoi(word);
		stream >> word;
		v2 = std::stoi(word);
		stream >> word;
		weight = std::stoi(word);

		//add esges to matrix
		queue.push(Edge(v1, v2, weight));
		cout << v1 << " " << v2 << " " << weight << endl;
	}
}