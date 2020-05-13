#include "AdjacencyList.h"

#include<fstream>
#include<string>
#include<iostream>

using namespace std;

AdjacencyList::AdjacencyList() {
}

AdjacencyList::AdjacencyList(int vertexAmount) {
	createList(vertexAmount);
}

void AdjacencyList::createList(int vertexAmount) {
	list = new List[vertexAmount];
	this->vertexAmount = vertexAmount;

}

void AdjacencyList::addEdge(Edge* edge) {
	list[edge->v1].push(edge->v2, edge->weight);
	list[edge->v2].push(edge->v1, edge->weight);
}

void AdjacencyList::addEdgeOne(Edge* edge) {
	list[edge->v1].push(edge->v2, edge->weight);
}

void AdjacencyList::deleteDuplicates() {

}

ListElement* AdjacencyList::getNeighbours(int n) {
	return list[n].getElement(0);
}


void AdjacencyList::read(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	string word;

	stream >> word;
	vertexAmount = std::stoi(word);
	cout << "Vertex amount: " << vertexAmount << endl;

	createList(vertexAmount);

	stream >> word;
	int edgeAmount = std::stoi(word);
	cout << "Edge amount: " << edgeAmount << endl;

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
		addEdge(new Edge(v1, v2, weight));
	}
}

void AdjacencyList::print() {
	for (int i = 0; i < vertexAmount; ++i) {
		cout << "Vertex " << i << ": ";
		list[i].display();
	}
}

void AdjacencyList::printList() {
	Edge* edge;
	for (int i = 0; i < vertexAmount; ++i) {
	}
}