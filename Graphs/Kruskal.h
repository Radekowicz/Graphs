#pragma once
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "DSStruct.h"
#include "Queue.h"
#include "List.h"


class Kruskal
{
public:
	int vertexAmount;
	int edgeAmountmstMST;
	int weightMST;

	Queue* queue;
	DSStruct* set;
	AdjacencyList* listMST;
	AdjacencyMatrix* matrixMST;


public:
	Kruskal(AdjacencyMatrix* matrix);
	void makeQueue(AdjacencyMatrix* matrix);
	void makeMST(AdjacencyMatrix* matrix);
};

