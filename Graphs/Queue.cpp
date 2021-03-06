﻿#include "Queue.h"
#include <iostream>

using namespace std;

// Definicje metod obiektu Queue
//------------------------------

// Konstruktor - tworzy n elementową tablicę heap na kopiec
//---------------------------------------------------------
Queue::Queue(int n)
{
    Heap = new Edge*[n];   // Tworzymy tablicę
    heapPos = 0;           // Pozycja w kopcu
    this->vertexAmount = n;
    edgeCount = 0;
}



// Destruktor - usuwa kopiec z pamięci
//------------------------------------
Queue::~Queue()
{
    delete[] Heap;
}

// Zwraca krawędź z początku kopca
//--------------------------------
Edge* Queue::getFirstEdge()
{
    return Heap[0];
}

// Umieszcza w kopcu nową krawędź i odtwarza strukturę kopca
//----------------------------------------------------------
void Queue::push(Edge* e)
{
    int temp;
    int parent;

    temp = heapPos++;              // i ustawiamy na koniec kopca
    parent = (temp - 1) / 2;      // Obliczamy pozycję rodzica

    // Szukamy miejsca w kopcu dla e

    while (temp && (Heap[parent]->weight > e->weight))
    {
        Heap[temp] = Heap[parent];
        temp = parent;
        parent = (temp - 1) / 2;
    }

    Heap[temp] = e;          // Krawędź e wstawiamy do kopca
    edgeCount++;
}

// Usuwa korzeń z kopca i odtwarza jego strukturę
//-----------------------------------------------
void Queue::pop()
{
    int i, j;
    Edge* edge;

    if (heapPos != 0)
    {
        edge = Heap[--heapPos];

        i = 0;
        j = 1;

        while (j < heapPos)
        {
            if ((j + 1 < heapPos) && (Heap[j + 1]->weight < Heap[j]->weight)) j++;
            if (edge->weight <= Heap[j]->weight) break;
            Heap[i] = Heap[j];
            i = j;
            j = (2 * j) + 1;

        }
        Heap[i] = edge;
    }
}

void Queue::print() {
    for (int i = 0; i < vertexAmount; ++i) {
        Heap[i]->toString();
    }
}

void Queue::printTo(int n) {
    for (int i = 0; i < n; ++i) {
        Heap[i]->toString();
    }
}

bool Queue::edgeExists(Edge* edge) {
    int size = sizeof(Heap);
    cout << size;
    for (int i = 0; i < size; ++i) {
        if (Heap[i]->v1 == edge->v1 && Heap[i]->v2 == edge->v2 && Heap[i]->weight == edge->weight) {
            return true;
        }
    }
    return false;
}
