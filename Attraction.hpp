// Attraction.hpp
#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Attraction {

public:
    Attraction(string name, int maxPeople, double price);

    string getName();
    int getMaxPeople();
    double getPrice();


    string name;
    int maxPeople;
    double price;


};

#endif // ATTRACTION_HPP