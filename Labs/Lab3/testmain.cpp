#include "test.h"
#include <iostream>

using namespace std;

int main()
{
	Op op1(3);
	Op op2(5);
	Op op3(2);

	Mult m1(&op1, &op2);
	Add a1(&m1, &op3);

	cout << a1.evaluate() << endl;

	return 0;
}
