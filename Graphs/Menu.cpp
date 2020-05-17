using namespace std;

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <conio.h>

#include "Menu.h"
#include "Kruskal.h"
#include "Prim.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

void Menu::displayMenu(std::string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Wygeneruj graf losowo" << endl;
	cout << "3.Wyswietl" << endl;
	cout << "4.Algorytm Prima" << endl;
	cout << "5.Algorytm Kruskala" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void Menu::displayMenu2(std::string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Wygeneruj graf losowo" << endl;
	cout << "3.Wyswietl" << endl;
	cout << "4.Algorytm Dijkstry" << endl;
	cout << "5.Algorytm Bellmana-Forda" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}



void Menu::MSTMenu()
{
	AdjacencyMatrix* matrixGraph = new AdjacencyMatrix();
	AdjacencyList* listGraph = new AdjacencyList();
	//int vertexAmount;

	do {
		displayMenu("--- MST ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  grafu z pliku
			cout << " Podaj nazwe zbioru: ";
			cin >> fileName;
			matrixGraph->read(fileName);
			listGraph->read(fileName);
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '2': //tutaj generowanie losowego grafu
			cout << " Podaj liczbe wierzcholkow: ";
			cin >> vertexAmount;
			cout << " Podaj gestosc grafu w procentach (1-100): ";
			int percent;
			cin >> percent;
			matrixGraph->generateGraphUndirected2(vertexAmount, percent);
			listGraph = matrixGraph->convertToList();
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '3': //tutaj wyswietlanie grafu
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '4': //tutaj Prim
		{	
			Prim prim = Prim(listGraph);
			prim.makeMST(listGraph);
			prim.print();
			break;
		}

		case '5':  //tutaj Kruskal
		{
			Kruskal kruskal = Kruskal(matrixGraph);
			kruskal.makeMST(matrixGraph);
			kruskal.print();
			break;
		}

		}
	} while (opt != '0');
}


void Menu::SciezkaMenu()
{
	AdjacencyMatrix* matrixGraph = new AdjacencyMatrix();
	AdjacencyList* listGraph = new AdjacencyList();
	//int vertexAmount;

	do {
		displayMenu2("--- NAJKROTSZA SCIEZKA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  grafu z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			matrixGraph->read(fileName);
			listGraph->read(fileName);
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '2': //tutaj generowanie losowego grafu
			cout << " Podaj liczbe wierzcholkow:";
			cin >> vertexAmount;
			cout << " Podaj gestosc grafu w procentach (1-100):";
			int percent;
			cin >> percent;
			matrixGraph->generateGraphDirected2(vertexAmount, percent);
			listGraph = matrixGraph->convertToList();
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '3': //tutaj wyswietlanie grafu
			cout << endl << endl;
			matrixGraph->print();
			cout << endl << endl;
			listGraph->print();
			break;

		case '4': //tutaj Dijkstra
		{
			int startVertex;
			cout << " Podaj wierzcholek startowy: ";
			cin >> startVertex;
			cout << endl << endl;
			Dijkstra dijkstra = Dijkstra(listGraph);
			dijkstra.makeDijkstra(startVertex);
			dijkstra.print();
			break;
		}

		case '5':  //tutaj Bellman-Ford
		{
			int startVertex;
			cout << " Podaj wierzcholek startowy: ";
			cin >> startVertex;
			cout << endl << endl;
			BellmanFord bellmanFord = BellmanFord(listGraph);
			bellmanFord.makeBellmanFord(startVertex);
			bellmanFord.print();
			break;
		}

		}
	} while (opt != '0');
}