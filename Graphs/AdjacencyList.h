#pragma once
#include "List.h"
#include "Edge.h"
#include <string>

class AdjacencyList
{
public:
	int vertexAmount;
	int edgeAmount;
	List* list;

	AdjacencyList();
	void createList(int vertexAmount);
	void addEdge(Edge* edge);
	void read(std::string location);
	void print();
};

