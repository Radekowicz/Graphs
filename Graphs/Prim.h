#pragma once
#include "Queue.h"
#include "ListElement.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

class Prim
{
public:
	int vertexAmount;
	int edgeAmountmstMST;
	int weightMST;

	Queue* queue;
	AdjacencyList* listMST;
	AdjacencyMatrix* matrixMST;
	bool* visited;



	Prim(AdjacencyList* list);
	void makeMST(AdjacencyList* list);
	void print();
};

