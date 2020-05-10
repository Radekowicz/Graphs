#pragma once
#define _TOOLS_H_

class ListElement
{
public:
	int vertex;
	int weight;
	ListElement* next;
	ListElement* previous;
	 

public:
	ListElement(int vertex, int weight, ListElement* next, ListElement* previous);
};

