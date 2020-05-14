#include "Heap.h"

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
#include "MyArray.h"


using namespace std;

Heap::Heap() {
    array = new MyArray();
}

Heap::~Heap() {
    if ((array->getNumberOfElements()) > 0) {
        free(array);
    }
}

void Heap::display() {
    for (int i = 0; i < array->getNumberOfElements(); i++) {
        cout << array->get(i) << ' ';
    }
    cout << endl;
}

void Heap::repairDown(int parentIndex) {

    //definiowanie dzieci rodzica
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    bool rightExists = rightChildIndex < array->getNumberOfElements(); 

    if (rightExists) {
        if (array->get(leftChildIndex) < array->get(parentIndex) || array->get(rightChildIndex) < array->get(parentIndex)) { //tu zamiana

            //ustalanie które dziecko jest mniejsze
            int smallerChildIndex = 0;
            if (array->get(rightChildIndex) < array->get(leftChildIndex)) // tu zamiana
                smallerChildIndex = rightChildIndex;
            else
                smallerChildIndex = leftChildIndex;

            //zamiana miejscami
            int tempParent = array->get(parentIndex);
            array->set(parentIndex, array->get(smallerChildIndex));
            array->set(smallerChildIndex, tempParent);


            //nowy rodzic i rekurencyjne wywołanie funkcji
            if (smallerChildIndex <= (array->getNumberOfElements() - 2) / 2)
                cout << "1: " << array->get(leftChildIndex) << endl;
                repairDown(smallerChildIndex);
        }
        cout << "1: " << array->get(leftChildIndex) << endl;

    }
    else if (array->get(leftChildIndex) < array->get(parentIndex)) { //tu zamiana

        //zamiana miejscami
        int tempParent = array->get(parentIndex);
        array->set(parentIndex, array->get(leftChildIndex));
        array->set(leftChildIndex, tempParent);


        //nowy rodzic i rekurencyjne wywołanie funkcji
        if (leftChildIndex <= (array->getNumberOfElements() - 2) / 2)
            cout << "2: " << array->get(leftChildIndex) << endl;
            repairDown(leftChildIndex);
    }
    cout << "2: " << array->get(leftChildIndex) << endl;
}

void Heap::makeHeap() {

    int lastParentIndex = (array->getNumberOfElements() - 2) / 2;

    while (lastParentIndex > 0) {

        //naprawa kopca w dół
        repairDown(lastParentIndex);

        //nowy lastParent
        lastParentIndex--;
    }
}

void Heap::add(int value) {

    array->add(value);
    cout << "To add:" << value << endl;
    makeHeap();
}

bool Heap::elementExists(int value) {
    for (int i = 0; i < array->getNumberOfElements(); i++) {
        if (array->get(i) == value) return true;
    }
    return false;
}

void Heap::remove(int value) {
    for (int i = 0; i < array->getNumberOfElements(); i++) {
        if (array->get(i) == value) array->remove(i);
    }
    makeHeap();
}

void Heap::displayBT() {
    this->printBT("", "", 0);
}

void Heap::printBT(std::string sp, std::string sn, int v)
{
    std::string cr, cl, cp;
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    std::string s;
    int n = array->getNumberOfElements();

    if (v < n)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        this->printBT(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        cout << s << sn << array->get(v) << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        this->printBT(s + cp, cl, 2 * v + 1);
    }
}

void Heap::read(std::string location) {
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

void Heap::read2(std::string location) {
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


void Heap::generateHeap(int size) {
    for (int i = array->getNumberOfElements() - 1; i >= 0; i--) {
        array->remove(i);
    }
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        /* generate secret number between 1 and 100: */
        add(rand() % 100 + 1);
    }
}
