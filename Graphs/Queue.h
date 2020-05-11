#pragma once
#include "Edge.h"

class Queue
{
public:
    Edge* Heap;
    int heapPos;
    int n;
    int edgeCount;
public:
    Queue(int n);
    Queue();
    ~Queue();
    Edge getFirstEdge();
    void push(Edge e);
    void pop();
    void print();
    bool edgeExists(Edge edge);
};