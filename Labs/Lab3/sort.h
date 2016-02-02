#ifndef __SORT_H__
#define __SORT_H__

#include <iostream>
#include <vector>
#include <list>

#include "test.h"

using namespace std;

class Container;

class Sort {
    public:
        // Constructors
        Sort(){};

        // Pure Virtual Functions
        virtual void sort(Container* container) = 0;
};

#include "container.h"

class bubbleSort : public Sort {
    public:
        bubbleSort() {};

        void sort(Container* container) {
            bool swapped = true;
            int j = 0;
            int sz = container->size();

            while(swapped) {
                swapped = false;
                ++j;
                for (int i = 0; i < sz - j; i++) {
                    if ( container->at(i) > container->at(i + 1) ) {
                        container->swap(i, i+1);
                        swapped = true;
                    }
                }
            }
        }
};

class selectionSort : public Sort {
    public:
        selectionSort() {};

        void sort(Container* container) {
            int i, j, minIndex;
            int sz = container->size();
            for (i = 0; i < sz - 1; i++) {
                minIndex = i;
                for (j = i + 1; j < sz; ++j) {
                    if (container->at(j) < container->at(minIndex) ) {
                        minIndex = j;
                    }
                }

                if (minIndex != i) {
                    container->swap(i, minIndex);
                }
            }
        }

};

#endif
