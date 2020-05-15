#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

#include<fstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
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

void AdjacencyList::readDirected(std::string location) {
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
		addEdgeOne(new Edge(v1, v2, weight));
		//allVertexes->push(v1);
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

bool AdjacencyList::edgeExists(Edge* edge) {	
	if (list[edge->v1].elementExists(edge->v2)) return true;
	return false;
}


void AdjacencyList::generateGraphUndirected(int vertexAmount, float percent) { //nieskierowne krawedzie 
	this->vertexAmount = vertexAmount;

	createList(vertexAmount);

	int maxEdgeAmount = (vertexAmount * (vertexAmount - 1) / 2);
	edgeAmount = maxEdgeAmount * (percent / 100);
	cout << maxEdgeAmount << " " << edgeAmount << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		//cout <<  randomV1 << " ";
		randomV2 = rand() % vertexAmount - 1 + 1;
		//cout << randomV1 << " ";
		randomWeight = rand() % 9 + 1;
		 
		Edge* edge = new Edge(randomV1, randomV2, randomWeight);
		if (!edgeExists(edge) && !edgeExists(new Edge(edge->v2, edge->v1, edge->weight)) && edge->v1 != edge->v2) {
			//cout << "passed: ";
			edge->toString();
			addEdge(edge);
			loop++;
		}
	}
}


void AdjacencyList::generateGraphDirected(int vertexAmount, float percent) { //nieskierowne krawedzie 
	this->vertexAmount = vertexAmount;

	createList(vertexAmount);

	int maxEdgeAmount = (vertexAmount * (vertexAmount - 1));
	edgeAmount = maxEdgeAmount * (percent / 100);
	cout << maxEdgeAmount << " " << edgeAmount << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		//cout <<  randomV1 << " ";
		randomV2 = rand() % vertexAmount - 1 + 1;
		//cout << randomV1 << " ";
		randomWeight = rand() % 9 + 1;

		Edge* edge = new Edge(randomV1, randomV2, randomWeight);
		if (!edgeExists(edge) && edge->v1 != edge->v2) {
			cout << "passed: ";
			edge->toString();
			addEdgeOne(edge);
			loop++;
		}
	}
}