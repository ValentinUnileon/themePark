#include "Admin.hpp"
#include <iostream>
#include <string>

using namespace std;

Admin::Admin(string nameString, string idString, string adminNumber)
    : User(nameString, idString), adminID(adminNumber) {}


string Admin::getAdminID(){
    return adminID;
}

void Admin::setAdminID(string id){
    adminID=id;
}

void Admin::showAllAttractions(){

    if(attractions.size()>0){

        cout << "--------ATTRACTIONS----------" << endl;
        for(int i=0; i< attractions.size(); i++){
            cout<< i+1 << ". "<< attractions[i].getName() << endl; 
        }
        cout << "-----------------------------" << endl << endl;
    }
}

void Admin::addAttraction(Attraction attraction){
    attractions.push_back(attraction);
}

void Admin::createAttraction(){

    string name;
    int maxPeople;
    double price;

    cout << "Introduce the name of the attraction" << endl;
    cin >> name;
    cout << "Introduce the maximun number of people allowed in the attraction" << endl;
    cin >> maxPeople;
    cout << "Introduce the price of the ticket" << endl;
    cin >> price;
    Attraction newAttraciton(name, maxPeople, price);

    addAttraction(newAttraciton);

    cout << "Attraction created" << endl;
}

void Admin::deleteAttraction(){

    string name;
    cout << "Introduce the name of the attraction to delete" << endl;
    cin >> name;

    for(int i=0; i<attractions.size(); i++){
        if(attractions[i].getName()==name){
            attractions.erase(attractions.begin() + i);
        }
    }

    cout << "Attraction deleted" << endl;
}

vector<Attraction> Admin::getAttractions(){
    return attractions;
}