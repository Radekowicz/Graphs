#include "MyArray.h"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;


MyArray::MyArray() {
	allocatedMemory = 0;
	allocatedMemorySize = 0;
	numberOfElements = 0;
}

MyArray::~MyArray() {
	free(allocatedMemory);
}

int MyArray::get(int index) {
	return allocatedMemory[index];
}

void MyArray::set(int index, int value) {
	allocatedMemory[index] = value;
}


void MyArray::add(int value) {

	numberOfElements++;

	if (numberOfElements > allocatedMemorySize || allocatedMemorySize == 0) {

		try {
			allocatedMemorySize++;
			int* tempMemory = (int*)realloc(allocatedMemory, allocatedMemorySize * sizeof(int));
			if (tempMemory != NULL) {
				allocatedMemory = tempMemory;
				allocatedMemory[numberOfElements - 1] = value;
			}
			else
				cout << "Error" << endl;
		}
		catch (exception)
		{
			cout << "exception raised" << endl;
		}
	}
	else
		allocatedMemory[numberOfElements - 1] = value;
}

void MyArray::addWithIndex(int value, int index) {
	if (!(index > numberOfElements)) {

		numberOfElements++;

		if (numberOfElements > allocatedMemorySize) {
			try {
				allocatedMemorySize *= 2;
				int* tempMemory = (int*)realloc(allocatedMemory, allocatedMemorySize * sizeof(int));
				if (tempMemory != NULL) {
					allocatedMemory = tempMemory;
					for (int i = numberOfElements - 1; i >= index; i--) {
						allocatedMemory[i + 1] = allocatedMemory[i];
					}
					allocatedMemory[index] = value;
				}
				else
					cout << "Error" << endl;
			}
			catch (exception)
			{
				cout << "exception raised" << endl;
			}
		}
		else {
			for (int i = numberOfElements - 1; i >= index; i--) {
				allocatedMemory[i + 1] = allocatedMemory[i];
			}
			allocatedMemory[index] = value;

		}
	}
	else
		cout << "Error: index out of array" << endl;
}

void MyArray::remove(int index) {
	for (int i = index; i < numberOfElements - 1; i++) {
		allocatedMemory[i] = allocatedMemory[i + 1];
	}
	numberOfElements--;

	if (numberOfElements < allocatedMemorySize / 2) {
		try {
			allocatedMemorySize /= 2;
			int* tempMemory = (int*)realloc(allocatedMemory, allocatedMemorySize * sizeof(int));
			if (tempMemory != NULL) {
				allocatedMemory = tempMemory;
			}
			else
				cout << "Error" << endl;
		}
		catch (exception)
		{
			cout << "exception raised" << endl;
		}
	}
}

bool MyArray::elementExists(int value) {
	for (int i = 0; i < numberOfElements; i++) {
		if (allocatedMemory[i] == value) return true;
	}
	return false;
}

void MyArray::display() {
	for (int i = 0; i < numberOfElements; i++) {
		cout << allocatedMemory[i] << " ";
	}
	cout << endl;
}


int MyArray::getNumberOfElements() {
	return numberOfElements;
}


void MyArray::setAllocatedMemorySize(int allocatedMemorySize) {
	MyArray::allocatedMemorySize = allocatedMemorySize;
}

int* MyArray::getAllocatedMemory() {
	return allocatedMemory;
}

void MyArray::read(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	std::string word;
	stream >> word;
	int loop = std::stoi(word);
	for (int i = 0; i < loop; i++) {
		stream >> word;
		add(std::stoi(word));
	}
}


void MyArray::read2(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	std::string word;
	stream >> word;
	while (stream.good()) {
		add(std::stoi(word));
		stream >> word;
	}
}

void MyArray::generateArray(int numberOfElements) {
	for (int i = MyArray::numberOfElements - 1; i >= 0; i--) {
		remove(i);
	}
	srand(time(NULL));
	for (int i = 0; i < numberOfElements; i++) {
		/* generate secret number between 1 and 100: */
		add(rand() % 100 + 1);
	}
}
