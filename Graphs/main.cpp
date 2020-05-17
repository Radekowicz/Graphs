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

//teraz liczymy bellmana
void count(int vertexAmount, int percent) {
	Time time = Time();
	double sumTime = 0;
	AdjacencyMatrix* matrix = new AdjacencyMatrix();
	AdjacencyList* list;
	int x = 20;

	for (int i = 0; i < x; i++) {
		matrix->generateGraphUndirected2(vertexAmount, percent);
		//list = matrix->convertToList();

		time.start();
		Kruskal kruskal = Kruskal(matrix);
		kruskal.makeMST(matrix);

		sumTime += time.stopAndPrint2();
	}

	cout << sumTime / x << endl;
}


int main() {
	/*
	int x = 20;

	count(50, x);
	count(100, x);
	count(200, x);
	count(300, x);
	count(500, x);
	count(800, x);
	//count(1000, x);
	*/


	


	//parametry grafu
	int vertexAmount = 5;
	int percent = 40;

	AdjacencyMatrix* matrix = new AdjacencyMatrix(vertexAmount);
	//matrix->read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	matrix->generateGraphUndirected2(vertexAmount, percent);
	matrix->print();

	Kruskal kruskal = Kruskal(matrix);
	kruskal.makeMST(matrix);
	kruskal.print();

	/*
	AdjacencyList* list = new AdjacencyList();
	list->read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	list->print();

	Prim prim = Prim(list);
	prim.makeMST(list);
	*/


	
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