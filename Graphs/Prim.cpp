#include "Prim.h"
#include "ListElement.h"
#include "Queue.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "List"
#include<iostream>

using namespace std;

Prim::Prim(AdjacencyList* list) {
	vertexAmount = list->vertexAmount;
	weightMST = 0;
	visited = new bool[vertexAmount];
    listMST = new AdjacencyList(vertexAmount);
    matrixMST = new AdjacencyMatrix(vertexAmount);
}
 
void Prim::makeMST(AdjacencyList* list) {
    Edge* edge;

    for (int i = 0; i < vertexAmount; ++i)
        visited[i] = false;       // Inicjujemy tablicę odwiedzin

    int v = 0;                         // Wierzchołek startowy
    visited[v] = true;          // Oznaczamy go jako odwiedzonego

    int inQueue = 0;
    ListElement* p;

    for (int i = 1; i < vertexAmount; ++i)       // Do drzewa dodamy n - 1 krawędzi grafu
    {
        queue = new Queue(list->edgeAmount);
        p = list->getNeighbours(v);  // Przeglądamy listę sąsiadów

        do {
            if (visited[p->vertex] == false)    // Jeśli sąsiad jest nieodwiedzony, 
            {
                edge = new Edge(v, p->vertex, p->weight); // to tworzymy krawędź
                queue->push(edge);            // Dodajemy ją do kolejki priorytetowej
                inQueue++;
            }
            p = p->next;
        } while (p != NULL);

        do {
            edge = queue->getFirstEdge();            // Pobieramy krawędź z kolejki
            queue->pop();
          //  inQueue--;
        } while (visited[edge->v2] == true); // Krawędź prowadzi poza drzewo?


        listMST->addEdge(edge);             // Dodajemy krawędź do drzewa rozpinającego
        matrixMST->addEdge(edge);
        weightMST += edge->weight;
        visited[edge->v2] = true;     // Oznaczamy drugi wierzchołek jako odwiedzony
        v = edge->v2;

    }
}

void Prim::print() {
    cout << "MST adjacency list representation:" << endl << endl;
    listMST->print();
    cout << endl << "MST adjacency matrix representation:" << endl << endl;
    matrixMST->print();
    cout << endl << endl << "Total MST weight: " << weightMST << endl;
}

