#pragma once
#include "Queue.h"

struct Node
{
    int parent;
    int rank;
};

class DSStruct
{
private:
    Node* tableOfNodes;
public:
    DSStruct(int n);
    ~DSStruct();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(Edge e);
};
