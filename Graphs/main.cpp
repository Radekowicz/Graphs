#include "Kruskal.h"
#include "Prim.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Menu.h"
#include "Time.h"

#include<iostream>
#include<fstream>
#include <conio.h>
#include<string>
using namespace std;

/*
void count(int vertexAmount, int percent) {
	Time time = Time();
	double sumTime = 0;
	AdjacencyMatrix* matrix = new AdjacencyMatrix();
	AdjacencyList* list;
	int x = 1;
	Prim prim;

	for (int i = 0; i < x; i++) {
		matrix->generateGraphUndirected2(vertexAmount, percent);
		list = matrix->convertToList();

		time.start();
		
		sumTime += time.stopAndPrint2();
	}

	cout << sumTime / x << endl;
}
*/


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
	
	return 0;
}