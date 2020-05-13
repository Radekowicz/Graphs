#pragma once
#include "Queue.h"

struct Node
{
    int parent;
    int rank;
};

class DSStruct
{
public:
    Node* tableOfNodes;
public:
    DSStruct(int n);
    ~DSStruct();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(Edge* edge);
};
