#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Attraction.hpp"


using namespace std;

class Visitor : public User{

public:

    // visitorNumber -> a number for each that increases when a new visitor enters
    Visitor(string name, string id, int visitorNumber);

    int getVisitorNumber();
    void setVisitorNumber(int num);
    void setBill(double bill);
    double getBill();
    void addVisitedAttraction(Attraction attraction);
    vector<Attraction> getVisitedAttractions();


    int visitorNumber;
    vector<Attraction> attractionVisited;
    double totalPrice;



};

#endif // VISITOR_HPP