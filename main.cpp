#include <vector>
#include <iostream>
#include <algorithm>

#include "Attraction.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "Visitor.hpp"


using namespace std;

bool checkAdminInside(Admin admin);
bool checkVisitorInside(Visitor visitor);

vector<Attraction> attractions;
vector<Visitor> visitorList;
vector<Admin> adminList;
int numVisitor=0;

int main() {

    //cuando se abre la aplicacion se solicitará un dni
    //si el dni es de un admin se pasa al panel de control de admin
    //si es de visitante al panel de control del visitante

        std::cout << R"(
 _______ _                           _____           _
|__   __| |                         |  __ \         | |
   | |  | |__   ___ _ __ ___   ___  | |__) |_ _ _ __| | __
   | |  | '_ \ / _ \ '_ ` _ \ / _ \ |  ___/ _` | '__| |/ /
   | |  | | | |  __/ | | | | |  __/ | |  | (_| | |  |   <
   |_|  |_| |_|\___|_| |_| |_|\___| |_|   \__,_|_|  |_|\_\                                                
    )" << std::endl;

    Visitor exampleVisitor1("paco", "1234", numVisitor);
    numVisitor++;
    Visitor exampleVisitor2("lucia", "1234A", numVisitor);
    numVisitor++;

    Admin exampleAdmin1("valentin", "4321", "A123");
    
    visitorList.push_back(exampleVisitor1);
    visitorList.push_back(exampleVisitor2);

    adminList.push_back(exampleAdmin1);

    cout<< exampleAdmin1.getAdminID() << "-------------------" << endl;


    string type;
    string exit=true;
    int option;

    cout << "Welcome to the Krakow theme park " << endl;

    cout << "Are you an Administrator (A) or a Visitor (V) ?" << endl;
    cin >> type;

    while(exit){

        if(type=="A"){

            exit=false;

        }else if(type=="V"){

            exit=false;

        }else{
            cout<< "This is not a valid option";
        }



    }






    

    return 0;

}
