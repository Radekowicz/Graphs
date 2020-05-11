#pragma once
class Edge
{
public:
	int v1;
	int v2;
	int weight;

	Edge();

	Edge(int v1, int v2, int weight);

	void toString();
};


