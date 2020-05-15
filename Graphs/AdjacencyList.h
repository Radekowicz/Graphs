#pragma once
#include "List.h"
#include "ListElement.h"
#include "Edge.h"
#include "Queue.h"
#include <string>

class AdjacencyList
{
public:
	int vertexAmount;
	int edgeAmount;
	List* list;
	List* allVertexes;

	AdjacencyList();
	AdjacencyList(int vertexAmount);
	void createList(int vertexAmount);
	void addEdge(Edge* edge);
	void addEdgeOne(Edge* edge);
	void read(std::string location);
	void readDirected(std::string location);
	void print();
	void printList();
	ListElement* getNeighbours(int n);
	void deleteDuplicates();
	void generateGraphUndirected(int vertexAmount, float percent);
	void generateGraphDirected(int vertexAmount, float percent);
	bool edgeExists(Edge* edge);

};

