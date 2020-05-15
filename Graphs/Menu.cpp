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
	cout << "4.Algorytm Dijkstry" << endl;
	cout << "5.Algorytm Bellmana-Forda" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void Menu::SciezkaMenu()
{
	AdjacencyMatrix* matrixGraph = new AdjacencyMatrix();
	AdjacencyList* listGraph = new AdjacencyList();
	//int vertexAmount;

	do {
		displayMenu("--- TABLICA ---");
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
			matrixGraph->generateGraphUndirected(vertexAmount, percent);
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

		case '4': //tutaj prim
		{
			cout << endl << endl;
			Prim prim = Prim(listGraph);
			prim.makeMST(listGraph);
			break;
		}

		case '5':  //tutaj kruskal
		{
			cout << endl << endl;
			Kruskal kruskal = Kruskal(matrixGraph);
			kruskal.makeMST(matrixGraph);
			break;
		}

		}
	} while (opt != '0');
}

void Menu::MSTMenu()
{
	AdjacencyMatrix* matrixGraph = new AdjacencyMatrix();
	AdjacencyList* listGraph = new AdjacencyList();
	//int vertexAmount;

	do {
		displayMenu("--- TABLICA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  grafu z pliku
			cout << " Podaj nazwe zbioru: ";
			cin >> fileName;
			matrixGraph->readDirected(fileName);
			listGraph->readDirected(fileName);
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
			matrixGraph->generateGraphDirected(vertexAmount, percent);
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
			cout << " Podaj wierzcholek startowy: ";
			int startVertex;
			cin >> startVertex;
			cout << endl << endl;
			Dijkstra dijkstra = Dijkstra(listGraph);
			dijkstra.makeDijkstra(startVertex);
			break;
		}

		case '5':  //tutaj Bellman-Ford
		{
			cout << " Podaj wierzcholek startowy: ";
			int startVertex;
			cin >> startVertex;
			cout << endl << endl;
			BellmanFord bellmanFord = BellmanFord(listGraph);
			bellmanFord.makeBellmanFord(startVertex);
			break;
		}

		}
	} while (opt != '0');
}
