#include "Edge.h"
#include <iostream>

using namespace std;

Edge::Edge() {

}

Edge::Edge(int v1, int v2, int weight) {
	this->v1 = v1;
	this->v2 = v2;
	this->weight = weight;
}

void Edge::toString() {
	cout << v1 << " " << v2 << " " << weight << endl;
}

