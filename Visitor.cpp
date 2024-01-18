#include "Visitor.hpp"
#include <iostream>
#include <string>

using namespace std;

Visitor::Visitor(string nameString, string idString, int numVisitor)
    : User(nameString, idString), visitorNumber(numVisitor) {}


int Visitor::getVisitorNumber(){
    return visitorNumber;
}




