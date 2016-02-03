#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
//#include "sort.h"
#include "test.h"

using namespace std;

class Sort;

class Container {
    protected:
        Sort* sort_function;

    public:
        // Constructors
        Container() : sort_function(NULL) {};
        Container(Sort* function) : sort_function(function) {};

        // Non virtual functions
        void set_sort_function(Sort* sort_function) {
            this->sort_function = sort_function;
        }

        // Pure virtual functions
        virtual void add_element(Base* element) = 0;
        virtual void print() = 0;
        virtual void sort() = 0;
        virtual void swap(int i, int j) = 0;
        virtual Base* at(int i) = 0;
        virtual int size() = 0;
};

#include "sort.h"

class vecContainer : public Container {
    private:
        vector<Base*> baseVec;

    public:
        vecContainer() : Container() {};

        // Pure virtual implementations
        int size() {
            return baseVec.size();
        }

        void add_element(Base* element) {
            baseVec.push_back(element);
        }        

        void print() {
            // does below line even work
            int sz = baseVec.size();
            for(int i = 0; i < sz; i++)
            {
            	cout << baseVec.at(i)->evaluate() << " ";
            }
        }

        void sort() {
            sort_function->sort(this);
        }

        void swap(int i, int j) {
            iter_swap(baseVec.begin() + i, baseVec.begin() + j);
        }

        Base* at(int i) {
            return baseVec.at(i);
        }

};

class listContainer : public Container {
    private:
        list<Base*> baseList;

    public:
        listContainer() : Container() {};

        int size() {
            return baseList.size();
        }

        void add_element(Base* element) {
            baseList.push_back(element);
        }

        void print() {
            list<Base*>::iterator it;
            for(it = baseList.begin(); it != baseList.end(); ++it)
            {
            	 cout << (*it)->evaluate() << " ";
			}
       }

        void sort() {
            sort_function->sort(this);
        }

       void swap(int i, int j) {
			//not sure if this works yet
			list<Base*>::iterator it1 = baseList.begin();
			for(int x = 0; x < i; x++)
			{
				it1++;
			}
			list<Base*>::iterator it2 = baseList.begin();
			for(int y = 0; y < j; y++)
			{
				it2++;
			}
			iter_swap(it1, it2);
       }

        Base* at(int i) {
            int sz = baseList.size();
			if(sz > i)
			{
				list<Base*>::iterator it = baseList.begin();
				advance(it, i);
                return *it;
			}
            else {
                cout << "Out of Range" << endl;
                exit(0);
            }
       }

 
};

#endif
