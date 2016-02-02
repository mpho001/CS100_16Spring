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
    
    cout << "Test Cast 2: " <<  d1.evaluate() << endl;

    //////////////////////////////////////////////////
    cout << "Testing vector container " << endl;
    vecContainer myVector;

    myVector.add_element(&d1);
    myVector.add_element(&s1);
    int sz = myVector.size();
    cout << "vector size: " << sz << endl;
    myVector.print(); cout << endl;
    cout << "swap results: ";
    myVector.swap(0,1);
    myVector.print(); cout << endl;

    // testing bubbleeeee
    cout << "bubble sort: ";
    bubbleSort bubble;
    myVector.set_sort_function(&bubble);
    myVector.sort();
    myVector.print(); cout << endl;

	return 0;
}
