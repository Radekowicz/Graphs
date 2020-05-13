#pragma once
#include "List.h"
#include "ListElement.h"
#include "Edge.h"
#include <string>

class AdjacencyList
{
public:
	int vertexAmount;
	int edgeAmount;
	List* list;

	AdjacencyList();
	AdjacencyList(int vertexAmount);
	void createList(int vertexAmount);
	void addEdge(Edge* edge);
	void addEdgeOne(Edge* edge);
	void read(std::string location);
	void print();
	void printList();
	ListElement* getNeighbours(int n);
	void deleteDuplicates();

};

