// Attraction.hpp
#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"

using namespace std;

class Attraction {

public:
    Attraction(string name, int maxPeople, double price);

    string getName();
    int getMaxPeople();
    double getPrice();
    vector<User> getUsers();

    //no setters needed    

    string name;
    int maxPeople;
    double price;
    vector<User> users;

};

#endif // ATTRACTION_HPP