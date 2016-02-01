#ifndef __SORT_H__
#define __SORT_H__

#include <iostream>
#include <vector>
#include <list>
#include "Container.h"

using namespace std


class Sort {
    public:
        // Constructors
        Sort();

        // Pure Virtual Functions
        virtual void sort(Container* container) = 0;
};

class bubbleSort : public Sort {
    public:
        bubbleSort() {};

        void sort(Container* container) {
            


        }
















#endif
