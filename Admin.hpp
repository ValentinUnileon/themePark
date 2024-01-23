#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Attraction.hpp"

using namespace std;

class Admin : public User{

public:

    Admin(string name, string id, string adminID);

    string getAdminID();
    void setAdminID(string id);
    void addAttraction(Attraction attraction);

    //Functionalities of an Admin

    void showAllAttractions();
    void createAttraction();
    void deleteAttraction();

    string adminID;
    vector<Attraction> attractions;


};