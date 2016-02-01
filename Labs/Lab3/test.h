#ifndef __TEST_H__
#define __TEST_H__

using namespace std;

class Base
{
	public:
		Base() {};
		virtual void evaluate() = 0;
};

class Op : public Base
{
	private:
		double operand;
	public:
		Op(double x):operand(x) {};
		virtual double evaluate() {return operand};
};


#endif
