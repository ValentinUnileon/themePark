#include <vector>
#include <iostream>
#include <algorithm>


#include "Attraction.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "Visitor.hpp"


using namespace std;

Admin* checkAdminInside(string id);
Visitor* checkVisitorInside(string id);
void showAllVisitors();
void rideAnAttraction(Visitor* visitor);
void showAttractionsVisited(Visitor* visitor);

Admin exampleAdmin1("valentin", "4321", "A123");


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

    Visitor exampleVisitor1("valentin", "1234B", numVisitor);
    numVisitor++;
    Visitor exampleVisitor2("pablo", "1234A", numVisitor);
    numVisitor++;

    Attraction attraction("HauntedHouse", 20, 20.0);
    Attraction attraction2("Roaller coaster", 15, 20.0);
    Attraction attraction3("LiveShows", 50, 25.0);


    exampleAdmin1.addAttraction(attraction);
    exampleAdmin1.addAttraction(attraction2);
    exampleAdmin1.addAttraction(attraction3);
    
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

            char response;
            Visitor* visitor;
            
            cout << "Are you new here? Yes (Y) No (N)" << endl;
            cin >> response;

            if(response=='Y'){
                string name;
                string id;
                cout << "Insert your name" << endl;
                cin >> name;
                cout << "Insert your id" << endl;
                cin >> id;

                visitor = new Visitor(name, id, numVisitor);
                numVisitor++;

            }else{
                string id;
                cout << "Introduce the visitor ID ";
                cin >> id;
                
                visitor = checkVisitorInside(id);
            }



            if(visitor!=nullptr){


                exit=0;

                int visitorSelection=1;
                int choice;

                while(visitorSelection){
                    
                    cout << "Choose an option" << endl;
                    cout << "1. Ride an attraction" << endl;
                    cout << "2. See the bill" << endl;
                    cout << "3. See visited attractions" <<endl;
                    cout << "4. Exit" <<endl;

                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        rideAnAttraction(visitor);
                        break;
                    case 2:
                        cout << "Total bill: "<< visitor->getBill() << endl;
                        break;
                    case 3:
                        showAttractionsVisited(visitor);
                        break;
                    case 4:
                        visitorSelection=0;
                        break;
                    default:
                        break;
                    }
                }
            }else{
                cout << "Visitor not found" << endl;
            }




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

Visitor* checkVisitorInside(string id) {
    for (int i = 0; i < visitorList.size(); i++) {
        if (id == visitorList[i].getId()) {
            return &visitorList[i]; 
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

void rideAnAttraction(Visitor* visitor){

    int choice;

    cout<< "Choose one" << endl << endl;
    exampleAdmin1.showAllAttractions();

    cin >>choice ;

    cout << "Riding the attraction..." << endl;
    cout << "..." << endl;
    cout << "..." << endl;
    cout << "Finished" << endl ;


    visitor->addVisitedAttraction(exampleAdmin1.getAttractions()[choice-1]);
    
    double bill = visitor->getBill() + exampleAdmin1.getAttractions()[choice-1].getPrice();
    
    visitor->setBill(bill);

}

void showAttractionsVisited(Visitor* visitor) {

    if(visitor->getVisitedAttractions().size()>0){

        cout << "---------VISITED ATTRACTIONS-------"<< endl;

        for(int i=0; i< visitor->getVisitedAttractions().size(); i++){
            cout << visitor->getVisitedAttractions()[i].getName() << endl;
        }

        cout << "-------------------------------------" << endl;

    }else{
        cout << "No visited attractions yet" << endl;
    }



}

