#pragma once
#include "Edge.h"
#include <string>


class AdjacencyMatrix
{
private:
	int vertexAmount;
	int** matrix;
public:
	AdjacencyMatrix();
	~AdjacencyMatrix();
	void createMatrix(int vertexAmount);
	void addEdge(Edge* edge);
	void fillMatrixWithZeros();
	void read(std::string location);
	void print();
};

