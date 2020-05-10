#include "AdjacencyMatrix.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


AdjacencyMatrix::AdjacencyMatrix() {

}

AdjacencyMatrix::~AdjacencyMatrix() {
	for (int i = 0; i < vertexAmount; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void AdjacencyMatrix::createMatrix(int vertexAmount) {
	matrix = new int* [vertexAmount];
	for (int i = 0; i < vertexAmount; ++i) {
		matrix[i] = new int[vertexAmount];
	}
}


void AdjacencyMatrix::addEdge(Edge* edge) {
		matrix[edge->v1][edge->v2] = edge->weight;
		matrix[edge->v2][edge->v1] = edge->weight;

}

void AdjacencyMatrix::fillMatrixWithZeros() {
	for (int i = 0; i < vertexAmount; ++i) {
		for (int j = 0; j < vertexAmount; ++j) {
			matrix[i][j] = 0;
		}
	}
}

void AdjacencyMatrix::read(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	string word;

	stream >> word;
	int vertexAmount = std::stoi(word);
	cout << "Vertex amount: " <<  vertexAmount << endl;

	//create matrix
	createMatrix(vertexAmount);

	//fill matrix with zeros
	fillMatrixWithZeros();

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
		cout << v1 << " " << v2 << " " << weight << endl;
	}
}

void AdjacencyMatrix::print() {
	for (int i = 0; i < vertexAmount; ++i) {
		for (int j = 0; j < vertexAmount; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

