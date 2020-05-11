#include "DSStruct.h"
#include <iostream>

using namespace std;

// Definicje metod obiektu DSStruct
//---------------------------------

// Konstruktor
DSStruct::DSStruct(int n)
{
    tableOfNodes = new Node[n];    // Tworzymy tablicę dla elementów zbiorów
}

// Destruktor
//-----------
DSStruct::~DSStruct()
{
    delete[] tableOfNodes;            // Usuwamy tablicę ze zbiorami
}

// Tworzy wpis w tablicy Z
//------------------------
void DSStruct::MakeSet(int v)
{
    tableOfNodes[v].parent = v;
    tableOfNodes[v].rank = 0;
}

// Zwraca indeks reprezentanta zbioru, w którym jest wierzchołek v
//----------------------------------------------------------------


int DSStruct::FindSet(int v)
{
    if (tableOfNodes[v].parent != v) tableOfNodes[v].parent = FindSet(tableOfNodes[v].parent);
    return tableOfNodes[v].parent;
}


/*
int DSStruct::FindSet(int v)
{
    if (tableOfNodes[v].parent = v) return v;
    else return FindSet(tableOfNodes[v].parent);
}
*/

/*
int DSStruct::FindSet(int v)
{
    int a = v;
    while (tableOfNodes[a].parent != a) tableOfNodes[a].parent = a;
    return tableOfNodes[a].parent;
}
*/

// Łączy ze sobą zbiory z v i u
//-----------------------------
void DSStruct::UnionSets(Edge e)
{
    int root1, root2;

    root1 = FindSet(e.v1);   // Wyznaczamy korzeń drzewa z węzłem u
    root2 = FindSet(e.v2);   // Wyznaczamy korzeń drzewa z węzłem v
    if (root1 != root2)           // Korzenie muszą być różne
    {
        if (tableOfNodes[root1].rank > tableOfNodes[root2].rank) // Porównujemy rangi drzew
            tableOfNodes[root2].parent = root1;    // root2 większe, dołączamy root1
        else
        {
            tableOfNodes[root1].parent = root2;    // równe lub root1 większe, dołączamy root2
            if (tableOfNodes[root1].rank == tableOfNodes[root2].rank) tableOfNodes[root2].rank++;
        }
    }
}
