#include <vector>
#include <iostream>
#include <algorithm>

#include "Attraction.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "Visitor.hpp"


using namespace std;

Admin* checkAdminInside(string id);
bool checkVisitorInside(Visitor visitor);
void showAllVisitors();


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

    // -------------EXAMPLE INTRODUCTIONS -------------

    Visitor exampleVisitor1("ola", "1234", numVisitor);
    numVisitor++;
    Visitor exampleVisitor2("pablo", "1234A", numVisitor);
    numVisitor++;

    Attraction attraction("Haunted house", 20, 20.0);

    Admin exampleAdmin1("valentin", "4321", "A123");

    exampleAdmin1.addAttraction(attraction);
    
    visitorList.push_back(exampleVisitor1);
    visitorList.push_back(exampleVisitor2);

    adminList.push_back(exampleAdmin1);

    //--------------------------------------------------

    string type;
    bool exit=1;
    int option;

    cout << "Welcome to the Krakow theme park " << endl;

    cout << "Are you an Administrator (A) or a Visitor (V) ?" << endl;
    cin >> type;

    while(exit){  //check if the admin or visitor exist

        if(type=="A"){

            string id;
            cout << "Introduce the admin ID ";
            cin >> id;

            Admin* admin = checkAdminInside(id);

            if(admin!=nullptr){

                cout<< "You are an admin" << endl;

                exit=0;
                int choice;
                int adminSelection = 1;

                while(adminSelection){

                    cout << "Choose an option" << endl;
                    cout << "1. Show all atractions" << endl;
                    cout << "2. Create a new attraction" << endl;
                    cout << "3. Delete an attraction"<< endl;
                    cout << "4. Show all visitors" << endl;
                    cout << "5. Exit" << endl;

                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        admin->showAllAttractions();
                        break;
                    case 2: 
                        admin->createAttraction();
                        break;
                    case 3:
                        admin->deleteAttraction();
                        break;
                    case 4:
                        showAllVisitors();
                        break;
                    case 5:
                        adminSelection=0;
                        break;
                    
                    default:
                        break;
                    }

                }

            }else{
                cout << "This admin ID does not exist";
            }

        }else if(type=="V"){

            exit=0;

        }else{
            cout<< "This is not a valid option";
        }
    }


    return 0;

}


Admin* checkAdminInside(string id) {
    for (int i = 0; i < adminList.size(); i++) {
        if (id == adminList[i].getAdminID()) {
            return &adminList[i]; 
        }
    }
    return nullptr; 
}

void showAllVisitors(){

    if(visitorList.size()>0){
        
        cout << "----------VISITORS-----------" << endl;

        for(int i=0; i<visitorList.size(); i++){
            cout << visitorList[i].getName() << endl; 
        }

        cout << "-----------------------------" << endl;

    }


}