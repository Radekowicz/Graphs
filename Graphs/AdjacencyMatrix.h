#pragma once
#include "Edge.h"
#include <string>


class AdjacencyMatrix
{
public:
	int vertexAmount;
	int edgeAmount;
	int** matrix;
public:
	AdjacencyMatrix();
	~AdjacencyMatrix();
	void createMatrix(int vertexAmount);
	void addEdge(Edge* edge);
	void fillMatrixWithZeros();
	void read(std::string location);
	void print();
	int toQueue(int i, int j);
};

