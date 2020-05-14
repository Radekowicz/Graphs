#pragma once

#include "MyArray.h"
#include <string>

class Heap
{
public:
	MyArray* array;

public:
	Heap();

	~Heap();

	void repairDown(int parentIndex);

	void makeHeap();

	void display();

	void add(int value);

	bool elementExists(int value);

	void remove(int value);

	void printBT(std::string sp, std::string sn, int v);

	void displayBT();

	void read(std::string location);

	void generateHeap(int size);

	void read2(std::string location);

};

