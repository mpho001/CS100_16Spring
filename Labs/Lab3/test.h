#ifndef __TEST_H__
#define __TEST_H__

using namespace std;

class Base
{
	public:
		Base() {};
		virtual double evaluate() = 0;
};

class Op : public Base
{
	private:
		double operand;
	public:
		Op(double x):operand(x) {};
		virtual double evaluate() {return operand;};
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

class Sqr : public OneOperand
{
	public:
		Sqr(Base* n) {midOp = n;};
		virtual double evaluate()
		{
			return midOp->evaluate() * midOp->evaluate();
		};
};

class Add : public TwoOperand
{
	public:
		Add(Base* l, Base* r) {leftOp = l; rightOp = r;};
		virtual double evaluate()
		{
			return leftOp->evaluate() + rightOp->evaluate();
		};
};

class Sub : public TwoOperand
{
	public:
		Sub(Base* l, Base* r) {leftOp = l; rightOp = r;};
		virtual double evaluate()
		{
			return leftOp->evaluate() - rightOp->evaluate();
		};
};

class Mult : public TwoOperand
{
	public:
		Mult(Base* l, Base* r) {leftOp = l; rightOp = r;};
		virtual double evaluate()
		{
			return leftOp->evaluate() * rightOp->evaluate();
		};
};

class Div : public TwoOperand
{
	public:
		Div(Base* l, Base* r) {leftOp = l; rightOp = r;};
		virtual double evaluate()
		{
			return leftOp->evaluate() / rightOp->evaluate();
		};
};

#endif
