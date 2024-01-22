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