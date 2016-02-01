#ifndef __LAB3_H__
#define __LAB3_H__
#include <iostream>

using namespace std;

class Base
{
    public:
        /* Constructors */
        Base() {};
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class Composite: public Base
{
    protected:
	Base* left;
	Base* right;
    public:
	/* Constructors */
	Composite(Base* lt, Base* rt)
        :left(lt), right(rt) {}
	
	Base* getLeft()
	{
	   return left;
	}
	
	Base* getRight()
	{
	   return right;
	}

        virtual double evaluate() = 0;
};
class Op: public Base
{
    private:
	double operand;
    public:
	Op(double o)
	:Base(), operand(o) {}
	double evaluate()
	{
	    return operand;
	}
};

class Mult: public Composite
{
   public:
	Mult(Base* lt, Base* rt)
	: Composite(lt, rt) {}
	

        double evaluate()
	{
            Base* lft = getLeft();
	    Base* rht = getRight();
	    double answer = 0;
	    //double left = &lft;
	    //double right = this->getLeft();
	    //answer = left * right;
	    return answer;
	}
};














#endif



 


    
