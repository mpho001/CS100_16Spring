#include "test.h" // make sure to change this when you change the file name
#include <iostream>
#include "container.h"
#include "sort.h"

using namespace std;

int main()
{
	Op op1(3);
	Op op2(5);
	Op op3(2);

	Mult m1(&op1, &op2);
	Add a1(&m1, &op3);
    Sub s1(&a1, &op1);

	cout << "Test Case 1: " << s1.evaluate() << endl;

    // Another test case
    
    Op op4(6);
    Sqr sq1(&op4);
    Div d1(&sq1, &op1);
    
    cout << "Test Case 2: " <<  d1.evaluate() << endl;

    //////////////////////////////////////////////////
    cout << "\nTesting vector container " << endl;
    vecContainer myVector;

    myVector.add_element(&d1);
    myVector.add_element(&s1);
    myVector.add_element(&sq1);
    int sz = myVector.size();
    cout << "vector size: " << sz << endl;
    myVector.print(); cout << endl;
    cout << "swap results: ";
    myVector.swap(0,1);
    myVector.print(); cout << endl;

    // testing bubbleeeee
    cout << "bubble sort: ";
    bubbleSort bubble;
    selectionSort select;
    myVector.set_sort_function(&bubble);
    myVector.sort();
    myVector.print(); cout << endl;
    myVector.swap(0, 1);
    myVector.print(); cout << endl;

    cout << "another vector" << endl;
    vecContainer v;
    v.add_element(&d1);
    v.add_element(&sq1);
    v.add_element(&d1);
    v.add_element(&sq1);
    v.add_element(&m1);
    v.set_sort_function(&select);
    v.print(); cout << endl;
    v.sort();
    cout << "selection sort: ";
    v.print(); cout << endl;

    /////////////////////////////////////////////////////
    cout << "\nTesting list container " << endl;
    listContainer myList;
    myList.add_element(&d1);
    myList.add_element(&sq1);
    myList.add_element(&m1);
    myList.add_element(&d1);
    myList.add_element(&d1);
    myList.add_element(&sq1);
    cout << "list size: " << myList.size() << endl;
    myList.print(); cout << endl;
    // myList.swap(0, 1);

    // testing select sort
    cout << "select sort: ";
    myList.set_sort_function(&select);
    myList.sort();
    myList.print(); cout << endl;
    myList.swap(2, 3);
    cout << "swapping: ";
    myList.print(); cout << endl;
    myList.set_sort_function(&bubble);
    myList.sort();
    cout << "bubble sort: ";
    myList.print(); cout << endl;

	return 0;
}
