#include "Kruskal.h"
#include "Prim.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	
	AdjacencyMatrix* matrix = new AdjacencyMatrix();
	matrix->read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	matrix->print();
	cout << endl;
	
	AdjacencyList* list = new AdjacencyList();
	list->read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	list->print();
	cout << endl;

	Prim prim = Prim(list);
	prim.makeMST(list);

	Kruskal kruskal = Kruskal(matrix);
	kruskal.makeMST(matrix);

	return 0;
}