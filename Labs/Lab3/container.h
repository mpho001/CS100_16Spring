#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
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
        void set_sort_function(Sort* sort_function);

        // Pure virtual functions
        virtual void add_element(Base* element) = 0;
        virtual void print() = 0;
        virtual void sort() = 0;
        virtual void swap(int i, int j) = 0;
        virtual Base* at(int i) = 0;
        virtual int size() = 0;
};

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
            for(int i = 0; i < baseVec.size(); i++)
            {
            	cout << baseVec.at(i)->evaluate();
            }
        }

        void sort() {
            cout << "FIXMEEEE" << endl;
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
            for(int i = 0; i < baseList.size(); i++)
            {
            	cout << baseList.at(i)->evaluate();
			}
       }

        void sort() {
            cout << "fix this shit" << endl;
        }

       void swap(int i, int j) {
            cout << "fix as well" << endl;
       }

        Base *at(int i) {
			if(baseList.size() > i)
			{
				list<Base*> it;
				advance(it, i);
			}
       }

 
};

#endif
