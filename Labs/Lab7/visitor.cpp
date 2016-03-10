#include <iostream>
#include <sstream>
#include "visitor.h"
#include "composite.h"

using namespace std;

void PrintVisitor::opNode(Op* op) {
    double temp = op->evaluate();
    ostringstream num;
    num << temp;
    if (output.empty()) {
        output = num.str();
    }
    else {
        output += " " + num.str();
    }
}

void PrintVisitor::rootNode() {
    return;
}

void PrintVisitor::sqrNode() {
    if (output.empty()) {
        output = "^2";
    }
    else output += " ^2";
}

void PrintVisitor::multNode() {
    if (output.empty()) {
        output = "*";
    }
    else output += " *";
}

void PrintVisitor::subNode() {
    if (output.empty()) {
        output = "-";
    }
    else output += " -";
}

void PrintVisitor::addNode() {
    if (output.empty()) {
        output = "+";
    }
    else output += " +";
}

void PrintVisitor::execute() {
    cout << output << endl;
}
