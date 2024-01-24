// Attraction.cpp
#include "Attraction.hpp"
#include <vector>
using namespace std;

Attraction::Attraction(string name, int maxPeople, double price) : name(name), maxPeople(maxPeople), price(price) {}


string Attraction::getName(){
    return name;
}

int Attraction::getMaxPeople(){
    return maxPeople;
}

double Attraction::getPrice(){
    return price;
}

