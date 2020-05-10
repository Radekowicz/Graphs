#include "ListElement.h"

ListElement::ListElement(int vertex, int weight, ListElement* next, ListElement* previous) {
	ListElement::vertex = vertex;
	ListElement::weight = weight;
	ListElement::next = next;
	ListElement::previous = previous;
}
