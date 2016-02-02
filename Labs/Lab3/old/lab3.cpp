#include <iostream>
#include "lab3.h"

using namespace std;

int main() {

    Base* left  = new Op(1);
    Base* right = new Op(2);
    //Op a(1);
    //Op b(2); 
    //left = a;
    //left = b;
    Mult b = Mult(left, right);

    Base* test = b.getLeft();

    



    return 0;

}
