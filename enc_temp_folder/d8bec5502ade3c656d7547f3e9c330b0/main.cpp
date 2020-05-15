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

	

	/*
	* list = new AdjacencyList();
	list->generateGraphUndirected(4, 100);
	cout << endl;
	list->print();
	cout << endl;
	*/



	/*
	AdjacencyMatrix* matrix = new AdjacencyMatrix();
	matrix->generateGraphUndirected(7, 100);
	cout << endl;
	//matrix->print();
	cout << endl;
	
	AdjacencyList* list = new AdjacencyList();
	list->generateGraphUndirected(5, 99);
	list->print();

	Prim* prim = new Prim(list);
	prim->makeMST(list);
	*/

	return 0;
}