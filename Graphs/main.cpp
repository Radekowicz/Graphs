#include "Kruskal.h"
#include "Prim.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Menu.h"

#include<iostream>
#include<fstream>
#include <conio.h>
#include<string>
using namespace std;

int main() {

	/*
	List list = List();
	list.pushBack(3);
	cout << list.get(0) << endl;
	cout << list.head->vertex << endl;
	list.remove(0);
	cout << list.isEmpty();
	*/
	
	/*
	AdjacencyMatrix* matrix = new AdjacencyMatrix(4);
	matrix->generateGraphDirected2(30, 80);
	//matrix->generateSpanningTreeUndirected();
	matrix->print();

	AdjacencyList* list = matrix->convertToList();
	list->print();


	BellmanFord bellmanFord = BellmanFord(list);
	bellmanFord.makeBellmanFord(29);
	bellmanFord.print();

	*/

	/*
	//works
	Dijkstra dijkstra = Dijkstra(list);
	dijkstra.makeDijkstra(3);
	dijkstra.print();
	*/

	//Kruskal kruskal = Kruskal(matrix);
	//kruskal.makeMST(matrix);

	//Prim prim = Prim(list);
	//prim.makeMST(list);
	
	
	/*
	Menu menu = Menu();

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.MST" << endl;
		cout << "2.Najkrotsza droga" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu.MSTMenu();
			break;

		case '2':
			menu.SciezkaMenu();
			break;

		}

	} while (option != '0');
	
	*/
	

	


	return 0;
}