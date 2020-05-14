#pragma once
#define _TOOLS_H_

#include<string>;

class MyArray
{
	int* allocatedMemory;
	int allocatedMemorySize;
	int numberOfElements;

public:

	MyArray();

	~MyArray();

	void add(int value);

	int get(int index);

	void set(int index, int value);

	void remove(int index);

	void display();

	int getNumberOfElements();

	void setAllocatedMemorySize(int allocatedMemorySize);

	int* getAllocatedMemory();

	bool elementExists(int value);

	void addWithIndex(int value, int index);

	void read(std::string location);

	void generateArray(int numberOfElements);

	void read2(std::string location);


};

