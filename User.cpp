#include "User.hpp"
#include <iostream>
#include <string>
using namespace std;


User::User(string nameString, string idString): name(nameString), id(idString) {}

string User::getName(){
    return name;
}

string User::getId(){
    return id;
}

void User::setName(string newName){
    name=newName;
}

void User::setId(string newId){
    id=newId;
}



