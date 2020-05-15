#pragma once

#include <string>
#include "Queue.h"
#include "AdjacencyList.h"
#include "ListElement.h"


class BellmanFord
{
public:
    const int MAXINT = 2147483647;
    int vertexAmount;
    int currentVertex;
    int startVertex;


    AdjacencyList* graphList; // Tablica list sąsiedztwa

    int* pathLength = new int[vertexAmount];       // Tablica kosztów dojścia
    int* previousVertex = new int[vertexAmount];       // Tablica poprzedników
    bool* visited = new bool[vertexAmount];      // Zbiory Q i S

public:
    BellmanFord(AdjacencyList* graphList);
    void makeBellmanFord(int startVertex);
    int findMin();
    std::string drawPath(int w);
    void print();
};

