#pragma once
#include "Edge.h"
#include <string>
#include "AdjacencyList.h"


class AdjacencyMatrix
{
public:
	int vertexAmount;
	int edgeAmount;
	int** matrix;
public:
	AdjacencyMatrix();
	AdjacencyMatrix(int vertexAmount);
	~AdjacencyMatrix();
	void createMatrix(int vertexAmount);
	void addEdge(Edge* edge);
	void addEdgeOne(Edge* edge);
	void fillMatrixWithZeros();
	void read(std::string location);
	void readDirected(std::string location);
	void print();
	int toQueue(int i, int j);
	void generateGraphUndirected(int vertexAmount, float percent);
	void generateGraphDirected(int vertexAmount, float percent);
	AdjacencyList* convertToList();
	void generateSpanningTree();
	void generateSpanningTreeUndirected();
	void generateGraphUndirected2(int vertexAmount, float percent);
	void generateGraphDirected2(int vertexAmount, float percent);

};

