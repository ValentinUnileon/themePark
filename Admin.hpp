#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"

using namespace std;

class Admin : public User{

public:

    Admin(string name, string id, string adminID);

    string getAdminID();
    void setAdminID(string id);

    string adminID;

};