#include "Visitor.hpp"
#include <iostream>
#include <string>

using namespace std;

Visitor::Visitor(string nameString, string idString, int numVisitor)
    : User(nameString, idString), visitorNumber(numVisitor) {}


int Visitor::getVisitorNumber(){
    return visitorNumber;
}

void Visitor::setVisitorNumber(int num){
    visitorNumber=num;
}

void Visitor::addVisitedAttraction(Attraction attraction){
    attractionVisited.push_back(attraction);
}

void Visitor::setBill(double bill){
    totalPrice=bill;
}

double Visitor::getBill(){
    return totalPrice;
}

vector<Attraction> Visitor::getVisitedAttractions(){
    return attractionVisited;
}