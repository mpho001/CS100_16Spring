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

class OneOperand : public Base
{
	public:
		Base* midOp;
		OneOperand() {};
		virtual double evaluate() {return 0;};
};

class TwoOperand : public Base
{
	public:
		Base* leftOp;
		Base* rightOp;
		TwoOperand() {};
		virtual double evaluate() {return 0;};
};
#endif
