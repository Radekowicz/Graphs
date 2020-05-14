#include <string>
#include "Dijkstra.h"
#include "Queue.h"
#include "AdjacencyList.h"
#include "ListElement.h"
#include "List.h"
#include <iostream>



using namespace std;

Dijkstra::Dijkstra(AdjacencyList* graphList) {
	this->graphList = graphList;
	vertexAmount = graphList->vertexAmount;
}

void Dijkstra::makeDijkstra(int startVertex) {
	this->startVertex = startVertex;
	pathLength = new int[vertexAmount];       // Tablica kosztów dojścia (d)
	previousVertex = new int[vertexAmount];       // Tablica poprzedników (p)
	visited = new bool[vertexAmount];      // false - jest w grafhList, true - jest w solutionList


	//inicializaja

	for (int i = 0; i < vertexAmount; ++i) {
		pathLength[i] = MAXINT;
		previousVertex[i] = -1;
		visited[i] = false;
	}
	pathLength[startVertex] = 0;

	//cout << startVertex << endl;

	for (int i = 0; i < vertexAmount; ++i) {

		currentVertex = findMin(); //wierzchołek o min pathLength, który visited[i] == false
		visited[currentVertex] = true;
		//cout << currentVertex << endl;

		ListElement* p = graphList->getNeighbours(currentVertex);  // Przeglądamy listę sąsiadów

		while (p != NULL && pathLength[currentVertex] != MAXINT) {
			//cout << "internation: " << i << endl;
			//cout << "current vertex: " << currentVertex << endl;
			//cout << "v: " << p->vertex << " path: " << pathLength[p->vertex] << endl;

				if (pathLength[currentVertex] + p->weight < pathLength[p->vertex]) {
					pathLength[p->vertex] = pathLength[currentVertex] + p->weight;
					previousVertex[p->vertex] = currentVertex;
				}
				//cout <<  currentVertex << " " << previousVertex[p->vertex] << endl;
				//cout << "path after: " << pathLength[p->vertex] << endl << endl;
				p = p->next;

		} 

	}

	//wyniki
}

int Dijkstra::findMin() {
	int vertex = 0;
	int min = MAXINT;
	for (int j = 0; j < vertexAmount; ++j) {
		if (visited[j] == false) {
			if (pathLength[j] < min) {
				min = pathLength[j];
				vertex = j;
			}
		}
	}
	return vertex;
}

std::string Dijkstra::drawPath(int w) {
	std::string XD = "";
	int start = w;
	
	while (previousVertex[w] != -1) {
		XD += std::to_string(previousVertex[w]);
		XD += " ";
		w = previousVertex[w];
	}
	
	return XD;
}

void Dijkstra::print() {
	cout << "Min path from vertex " << startVertex <<  " to:" << endl;

	std::string inf;

	for (int i = 0; i < vertexAmount; ++i) {
		inf = std::to_string(pathLength[i]);
		if (pathLength[i] == MAXINT) inf = "No path";

		cout << "Vertex " << i << ": "
			<< drawPath(i) << " "
			<< "$" << inf << endl;
	}
}


