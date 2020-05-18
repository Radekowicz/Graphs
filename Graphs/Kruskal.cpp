#include "Kruskal.h"
#include "Queue.h"
#include "DSStruct.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include<iostream>



using namespace std;

Kruskal::Kruskal(AdjacencyMatrix* matrix) {
	vertexAmount = matrix->vertexAmount;
	set = new DSStruct(vertexAmount); 
	weightMST = 0;
}

void Kruskal::makeQueue(AdjacencyMatrix* matrix) {
	queue = new Queue(2*matrix->edgeAmount);

	Edge* edge;
	for (int i = 0; i < matrix->vertexAmount; ++i) {
		for (int j = 0; j < matrix->vertexAmount; ++j) {
			int edgeWeight = matrix->toQueue(i, j);
			edge = new Edge(i, j, edgeWeight);
			if (edgeWeight != 0) {
				queue->push(edge);
				//edge->toString();
			}
		}
	}
	//cout << endl;
}

void Kruskal::makeMST(AdjacencyMatrix* matrix) {
	listMST = new AdjacencyList(vertexAmount);
	matrixMST = new AdjacencyMatrix(vertexAmount); 


	for (int i = 0; i < vertexAmount; ++i) {
		set->MakeSet(i);
	}

	makeQueue(matrix);	//tworzymy posortowaną kolejkę z krawędziami grafu

	Edge* edge;
	for (int i = 1; i < vertexAmount; ++i) // Pętla wykonuje się n - 1 razy !!!
	{
		do
		{
			edge = queue->getFirstEdge();      // Pobieramy z kolejki krawędź
			//edge->toString();
			queue->pop();						// Krawędź usuwamy z kolejki
		} while (set->FindSet(edge->v1) == set->FindSet(edge->v2));

		listMST->addEdge(edge);       // Dodajemy krawędź do drzewa
		matrixMST->addEdge(edge);
		weightMST += edge->weight;

		set->UnionSets(edge);     // Zbiory z wierzchołkami łączymy ze sobą
	}

}

void Kruskal::print() {
	cout << "MST adjacency list representation:" << endl << endl;
	listMST->print();
	cout << endl << "MST adjacency matrix representation:" << endl << endl;
	matrixMST->print();
	cout << endl << endl << "Total MST weight: " << weightMST << endl;
}



