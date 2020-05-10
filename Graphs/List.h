#pragma once
#define _TOOLS_H_
#include<iostream>
#include "ListElement.h"

class List {

	ListElement* head;
	ListElement* tail;
	ListElement* current;
	int size;


public:
	List();

	~List();

	void push(int vertex, int weight);

	void pushFront(int value);

	void pushBack(int value);

	void pushByIndex(int value, int index);

	void remove(int index);

	void removeByValue(int value);

	void display();

	bool elementExists(int value);

	void delElem();

	void read(std::string location);

	void generateList(int size);

	void read2(std::string location);

};

