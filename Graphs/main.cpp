#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	
	AdjacencyMatrix matrix = AdjacencyMatrix();
	matrix.read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	matrix.print();
	
	cout << endl;

	AdjacencyList list = AdjacencyList();
	list.read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	list.print();
	

	return 0;
}