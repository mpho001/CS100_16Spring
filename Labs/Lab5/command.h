#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand(double val) {
			root = new Op(val);
		}
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Base* cmd, double val) {
			root = new Add(cmd, new Op(val));
		}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public: 
		SubCommand(Base* cmd, double val) {
			root = new Sub(cmd, new Op(val));
		}
};

class MultCommand : public Command {
	//MultCommand Code Here
	MultCommand(Base* cmd, double val) {
		root = new Mult(cmd, new Op(val));
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	SqrCommand(double val) {
		root = new Sqr(new Op(val));
	}
};

#endif //__COMMAND_CLASS__
