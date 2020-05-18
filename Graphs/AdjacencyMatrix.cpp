#include "AdjacencyMatrix.h"

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>


using namespace std;


AdjacencyMatrix::AdjacencyMatrix() {
}

AdjacencyMatrix::AdjacencyMatrix(int vertexAmount) {
	this->vertexAmount = vertexAmount;
	createMatrix(vertexAmount);
	fillMatrixWithZeros();
}

AdjacencyMatrix::~AdjacencyMatrix() {
	for (int i = 0; i < vertexAmount; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void AdjacencyMatrix::createMatrix(int vertexAmount) {
	matrix = new int* [vertexAmount];
	for (int i = 0; i < vertexAmount; ++i) {
		matrix[i] = new int[vertexAmount];
	}
}


void AdjacencyMatrix::addEdge(Edge* edge) {
		matrix[edge->v1][edge->v2] = edge->weight;
		matrix[edge->v2][edge->v1] = edge->weight;

}

void AdjacencyMatrix::addEdgeOne(Edge* edge) {
	matrix[edge->v1][edge->v2] = edge->weight;
}

void AdjacencyMatrix::fillMatrixWithZeros() {
	for (int i = 0; i < vertexAmount; ++i) {
		for (int j = 0; j < vertexAmount; ++j) {
			matrix[i][j] = 0;
		}
	}
}

void AdjacencyMatrix::read(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	string word;

	stream >> word;
	vertexAmount = std::stoi(word);
	cout << "Vertex amount: " <<  vertexAmount << endl;

	//create matrix
	createMatrix(vertexAmount);

	//fill matrix with zeros
	fillMatrixWithZeros();

	stream >> word;
	edgeAmount = std::stoi(word);
	cout << "Edge amount: " << edgeAmount << endl;

	int loop = std::stoi(word);
	int v1, v2, weight;
	for (int i = 0; i < loop; ++i) {
		stream >> word;
		v1 = std::stoi(word);
		stream >> word;
		v2 = std::stoi(word);
		stream >> word;
		weight = std::stoi(word);

		//add esges to matrix
		addEdge(new Edge(v1, v2, weight));
		//cout << v1 << " " << v2 << " " << weight << endl;
	}
}

void AdjacencyMatrix::readDirected(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	string word;

	stream >> word;
	vertexAmount = std::stoi(word);
	cout << "Vertex amount: " << vertexAmount << endl;

	//create matrix
	createMatrix(vertexAmount);

	//fill matrix with zeros
	fillMatrixWithZeros();

	stream >> word;
	edgeAmount = std::stoi(word);
	cout << "Edge amount: " << edgeAmount << endl;

	int loop = std::stoi(word);
	int v1, v2, weight;
	for (int i = 0; i < loop; ++i) {
		stream >> word;
		v1 = std::stoi(word);
		stream >> word;
		v2 = std::stoi(word);
		stream >> word;
		weight = std::stoi(word);

		//add esges to matrix
		addEdgeOne(new Edge(v1, v2, weight));
		//cout << v1 << " " << v2 << " " << weight << endl;
	}
}

void AdjacencyMatrix::print() {
	for (int i = 0; i < vertexAmount; ++i) {
		for (int j = 0; j < vertexAmount; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int AdjacencyMatrix::toQueue(int i, int j) {
	return(matrix[i][j]);
}

void AdjacencyMatrix::generateGraphUndirected(int vertexAmount, float percent) { //nieskierowne krawedzie 
	this->vertexAmount = vertexAmount;

	createMatrix(vertexAmount);
	fillMatrixWithZeros();

	int maxEdgeAmount = (vertexAmount * (vertexAmount- 1)/2 + vertexAmount);
	edgeAmount = maxEdgeAmount * (percent / 100);
	//cout << maxEdgeAmount << " " << edgeAmount << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		//cout <<  randomV1 << " ";
		randomV2 = rand() % vertexAmount - 1 + 1;
		//cout << randomV1 << " ";
		randomWeight = rand() % 9 + 1;
		//cout << "weight:" << randomWeight << endl;
		//cout << matrix[randomV1][randomV2] << endl;
		if (matrix[randomV1][randomV2] == 0) {
			Edge* edge = new Edge(randomV1, randomV2, randomWeight);
			//edge->toString();
			addEdge(edge);
			//matrix[randomV1][randomV2] == randomWeight;
			//cout << matrix[randomV1][randomV2];
			loop++;
		}
		//cout << "matrix: " << matrix[randomV1][randomV2] << endl;
	}
}

void AdjacencyMatrix::generateGraphDirected(int vertexAmount, float percent) { //skierowane krawedzie 
	this->vertexAmount = vertexAmount;

	createMatrix(vertexAmount);
	fillMatrixWithZeros();

	int maxEdgeAmount = (vertexAmount * (vertexAmount - 1));
	edgeAmount = maxEdgeAmount * (percent / 100);
	//cout << maxEdgeAmount << " " << edgeAmount << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		//cout <<  randomV1 << " ";
		randomV2 = rand() % vertexAmount - 1 + 1;
		//cout << randomV1 << " ";
		randomWeight = rand() % 9 + 1;
		//cout << "weight:" << randomWeight << endl;
		//cout << matrix[randomV1][randomV2] << endl;
		if (matrix[randomV1][randomV2] == 0) {
			Edge* edge = new Edge(randomV1, randomV2, randomWeight);
			//edge->toString();
			addEdgeOne(edge);
			//matrix[randomV1][randomV2] == randomWeight;
			//cout << matrix[randomV1][randomV2];
			loop++;
		}
		//cout << "matrix: " << matrix[randomV1][randomV2] << endl;
	}
}

AdjacencyList* AdjacencyMatrix::convertToList() {
	AdjacencyList* list = new AdjacencyList(vertexAmount);
	int edgeAmount = 0;

	for (int i = 0; i < vertexAmount; ++i) {
		for (int j = 0; j < vertexAmount; ++j) {
			if (matrix[i][j] != 0) {
				list->addEdgeOne(new Edge(i, j, matrix[i][j]));
				edgeAmount++;
			}
			
		}
	}
	list->edgeAmount = edgeAmount;
	return list; 
}

void AdjacencyMatrix::generateSpanningTree() {


	List connected = List();
	List NOTconnected = List();

	int x = rand() % vertexAmount;
	connected.push(x, NULL);

	for (int i = 0; i < x; ++i) {
		NOTconnected.push(i, NULL);
	}
	for (int i = x+1; i < vertexAmount; ++i) {
		NOTconnected.push(i, NULL);
	}
	

	srand(time(NULL));
	int indexV1;
	int indexV2;
	int randomWeight;
	int v1, v2;
	while (NOTconnected.isEmpty() == false) {

		//cout << "NOT connected: ";
		//NOTconnected.display();
		//cout << "connected: ";
		//connected.display();

		if (NOTconnected.size > 0) indexV1 = rand() % (NOTconnected.size);
		else indexV1 = 0;

		indexV2 = rand() % connected.size;
		randomWeight = rand() % 9 + 1;
		
		v1 = NOTconnected.get(indexV1);
		v2 = connected.get(indexV2);

		//cout << "v1:" << v1 << "  v2:" << v2 << endl;

		Edge* edge = new Edge(v1, v2, randomWeight);
		addEdgeOne(edge);

		//cout << endl;

		NOTconnected.remove(indexV1);
		//cout << "NOT connected: ";
		//NOTconnected.display();

		connected.pushBack(v1);
		//cout << "connected: ";
		//connected.display();

		//cout << "is empty: " << NOTconnected.isEmpty() << endl << "---------------" << endl;
	}
}

void AdjacencyMatrix::generateSpanningTreeUndirected() {


	List connected = List();
	List NOTconnected = List();

	int x = rand() % vertexAmount;
	connected.push(x, NULL);

	for (int i = 0; i < x; ++i) {
		NOTconnected.push(i, NULL);
	}
	for (int i = x + 1; i < vertexAmount; ++i) {
		NOTconnected.push(i, NULL);
	}


	srand(time(NULL));
	int indexV1;
	int indexV2;
	int randomWeight;
	int v1, v2;
	while (NOTconnected.isEmpty() == false) {

		//cout << "NOT connected: ";
		//NOTconnected.display();
		//cout << "connected: ";
		//connected.display();

		if (NOTconnected.size > 0) indexV1 = rand() % (NOTconnected.size);
		else indexV1 = 0;

		indexV2 = rand() % connected.size;
		randomWeight = rand() % 9 + 1;

		v1 = NOTconnected.get(indexV1);
		v2 = connected.get(indexV2);

		//cout << "v1:" << v1 << "  v2:" << v2 << endl;

		Edge* edge = new Edge(v1, v2, randomWeight);
		addEdge(edge);

		//cout << endl;

		NOTconnected.remove(indexV1);
		//cout << "NOT connected: ";
		//NOTconnected.display();

		connected.pushBack(v1);
		//cout << "connected: ";
		//connected.display();

		//cout << "is empty: " << NOTconnected.isEmpty() << endl << "---------------" << endl;
	}
}


void AdjacencyMatrix::generateGraphUndirected2(int vertexAmount, float percent) { //nieskierowne krawedzie 
	this->vertexAmount = vertexAmount;

	createMatrix(vertexAmount);
	fillMatrixWithZeros();
	generateSpanningTreeUndirected();
	//print();
		
	int maxEdgeAmount = (vertexAmount * (vertexAmount - 1) / 2 - vertexAmount + 1);
	edgeAmount = maxEdgeAmount * (percent / 100);
	//cout << 2 * maxEdgeAmount << " " << 2 * edgeAmount << endl << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		randomV2 = rand() % vertexAmount - 1 + 1;
		randomWeight = rand() % 9 + 1;

		if (matrix[randomV1][randomV2] == 0 && randomV1 != randomV2) {
			Edge* edge = new Edge(randomV1, randomV2, randomWeight);
			addEdge(edge);

			loop++;
		}
	}
}

void AdjacencyMatrix::generateGraphDirected2(int vertexAmount, float percent) { //skierowane krawedzie 
	this->vertexAmount = vertexAmount;

	createMatrix(vertexAmount);
	fillMatrixWithZeros();
	generateSpanningTree();
	///print();

	int maxEdgeAmount = (vertexAmount * (vertexAmount - 1) - vertexAmount + 1);
	edgeAmount = maxEdgeAmount * (percent / 100);
	//cout << maxEdgeAmount << " " << edgeAmount << endl << endl;

	srand(time(NULL));
	int randomV1;
	int randomV2;
	int randomWeight;

	int loop = 0;
	while (loop < edgeAmount) {
		randomV1 = rand() % vertexAmount - 1 + 1;
		randomV2 = rand() % vertexAmount - 1 + 1;
		randomWeight = rand() % 9 + 1;

		if (matrix[randomV1][randomV2] == 0 && randomV1 != randomV2) {
			Edge* edge = new Edge(randomV1, randomV2, randomWeight);
			addEdgeOne(edge);

			loop++;
		}
	}
}




