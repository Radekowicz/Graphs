#pragma once
#include "Edge.h"

class Queue
{
public:
    Edge** Heap;
    int heapPos;
    int vertexAmount;
    int edgeCount;
public:
    Queue(int n);
    ~Queue();
    Edge* getFirstEdge();
    void push(Edge* edge);
    void pop();
    void print();
    void printTo(int n);
    bool edgeExists(Edge* edge);
};