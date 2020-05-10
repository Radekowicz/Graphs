#include "AdjacencyMatrix.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	AdjacencyMatrix matrix = AdjacencyMatrix();
	matrix.read("C:\\Users\\radek\\OneDrive\\Pulpit\\graph.txt");
	cout << endl;
	matrix.print();

	return 0;
}