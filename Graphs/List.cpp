#include<iostream>
#include "List.h"
#include "ListElement.h"
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

List::List() {
	head = NULL;
	tail = NULL;
	current = NULL;
	size = 0;
}

List::~List() {
	for (int i = 0; i < size; i++) {
		if (head != NULL) {
			current = head->next;
			delete head;
			head = current;
		}
	}
}

ListElement* List::getElement(int n) {
	current = head;
	for (int i = 0; i < n; i++) {
		current = current->next;
	}
	return current;
}


void List::push(int value, int weight) {
	if (head == NULL) {
		//jeśli head nie istnieje to stwórz nowy ListElement head z podaną wartścią i przyszpisz go do tail
		head = new ListElement(value, weight, NULL, NULL);
		tail = head;
	}
	else {
		current = head;
		head = new ListElement(value, weight, current, NULL);
		current->previous = head;
	}
	size++;
}

void List::pushFront(int value) {
	if (head == NULL) {
		//jeśli head nie istnieje to stwórz nowy ListElement head z podaną wartścią i przyszpisz go do tail
		head = new ListElement(value, NULL, NULL, NULL);
		tail = head;
	}
	else {
		current = head;
		head = new ListElement(value, NULL, current, NULL);
		current->previous = head;
	}
	size++;
}

void List::pushBack(int value) {

	if (head == NULL) {
		//jeśli head nie istnieje to stwórz nowy ListElement head z podaną wartścią i przyszpisz go do tail
		head = new ListElement(value, NULL, NULL, NULL);
		tail = head;
	}
	else {
		current = tail; //przypisujemy ostatni element do tymczasowego ListElement
		tail = new ListElement(value, NULL,  NULL, current); // tworzymy nowy ogon tail, który wskazuje do tyłu na current, czyli poprzedni ogon
		current->next = tail; // poprzedni ogon current wskazuje do przodu na nowy ogon tail
	}
	size++;
}

void List::pushByIndex(int value, int index) {

	//sprawdź czy wybrany index istnieje
	if (index < 0 || index > size)
		cout << "Index does not exist" << endl;

	//sprawdź czy wybrany index znajduje się na początku tablicy
	else if (index == 0)
		pushFront(value);

	//sprawdź czy wybrany index znajduje się na kańcu tablicy
	else if (index == size)
		pushBack(value);

	//sprawdź w której połowie listy znajduje się wybrany index
	else if (index < size / 2) {
		current = head;

		//szukanie miejsca do wstawenia nowego elementu
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		//stworzenie nowego elementu o podanej wartości na wskazującego na element który miał jego index
		ListElement* newElement = new ListElement(value, NULL, current, current->previous);
		ListElement* temp = current->previous;
		current->previous = newElement;
		temp->next = newElement;
		size++;
	}

	else {
		current = tail;

		//szukanie miejsca do wstawenia nowego elementu
		for (int i = size; i > index; i--) {
			current = current->previous;
		}

		//stworzenie nowego elementu o podanej wartości na wskazującego na element który miał jego index
		ListElement* newElement = new ListElement(value, NULL, current, current->previous);
		ListElement* temp = current->previous;
		current->previous = newElement;
		temp->next = newElement;
		size++;
	}
}

void List::delElem() {
	ListElement* temp = current;
	(current->previous)->next = temp->next;
	(current->next)->previous = temp->previous;
	delete[] temp;
	size--;
}

void List::remove(int index) {

	//sprawdź czy istnieje element o wybranym indexie
	if (index < 0 || index >= size) {
		cout << "Index does not exist" << endl;
	}

	else if (index == 0 && head->next == NULL) {
		head = NULL;
		tail = NULL;
		current = NULL;
		size = 0;
	}

	else if (index == 0) {
		current = head;
		head = current->next;
		head->previous = NULL;
		size--;
	}

	else if (index == size - 1) {
		current = tail;
		tail = current->previous;
		tail->next = NULL;
		size--;
	}

	//sprawdź w której połowie listy znajduje się wybrany index
	else if (index <= size / 2) {
		current = head;

		//szukanie elementu do usunięcia
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		delElem();
	}

	else {
		current = tail;

		//szukanie elementu do usunięcia
		for (int i = size; i > index + 1; i--) {
			current = current->previous;
		}
		delElem();
	}

}

void List::removeByValue(int value) {

	//sprawdzamy czy wartość nie leży w głowie
	if (head->vertex == value) {

		current = head;
		head = current->next;
		head->previous = NULL;
		size--;
	}

	//sprawdzamy czy wartość nie leży w ogonie
	else if (tail->vertex == value) {
		current = tail;
		tail = current->previous;
		tail->next = NULL;
		size--;
	}

	//usuwamy wszystkie elementy listy o podanej wartości
	else {
		current = head;
		for (int i = 1; i < size - 1; i++) {
			current = current->next;
			if (current->vertex == value) delElem();
		}
	}
}

bool List::elementExists(int vertex) {
	current = head;
	for (int i = 0; i < size - 1; i++) {
		if (current->vertex == vertex) return true;
		current = current->next;
	}
	if (size > 1)
		if (tail->vertex == vertex) return true;
	return false; 
}

void List::display() {
	if (head == NULL) cout << endl << endl;
	else {
		ListElement* current = head;
		do {
			cout << current->vertex << "|" << current->weight << "  ";
			current = current->next;
		} while (current != NULL);
		cout << endl << endl;
	}
}

void List::read(std::string location) {
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
		pushBack(std::stoi(word));
	}
}

void List::read2(std::string location) {
	ifstream stream;
	stream.open(location);

	if (!stream.is_open()) {
		exit(EXIT_FAILURE);
	}
	std::string word;
	stream >> word;
	while (stream.good()) {
		pushBack(std::stoi(word));
		stream >> word;
	}
}

void List::generateList(int size) {
	for (int i = 0; i < List::size; i++) {
		if (head != NULL) {
			current = head->next;
			delete[] head;
			head = current;
		}
	}
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		/* generate secret number between 1 and 100: */
		pushFront(rand() % 100 + 1);
	}
}

bool List::isEmpty() {
	if (head == NULL) return true;
	return false;
}

int List::get(int index) {
	int value;

	if (index < 0 || index >= size) {
		cout << "Index does not exist" << endl;
	}

	else if (index == 0) {
		return head->vertex;
	}

	else if (index == size - 1) {
		return tail->vertex;
	}

	//sprawdź w której połowie listy znajduje się wybrany index
	else if (index <= size / 2) {
		current = head;

		//szukanie elementu do usunięcia
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->vertex;
	}

	else {
		current = tail;

		//szukanie elementu do usunięcia
		for (int i = size; i > index + 1; i--) {
			current = current->previous;
		}
		return current->vertex;
	}
	 
}