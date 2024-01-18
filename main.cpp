#include <vector>
#include <iostream>
#include <algorithm>

#include "Attraction.hpp"
#include "User.hpp"
#include "Visitor.hpp"


using namespace std;

vector<Attraction> attractions;
vector<Visitor> visitorList;
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
    
    visitorList.push_back(exampleVisitor1);
    visitorList.push_back(exampleVisitor2);


    string id;
    int option;

    cout << "Welcome to the Krakow theme park " << endl;

    cout << "Introduce your ID " << endl;
    cin >> id;

    auto iterador = std::find_if(visitorList.begin(), visitorList.end(),
        [id]( Visitor& user) {
            return user.getId() == id;
        }
    );

    

    if (iterador != visitorList.end()) {
        
        std::cout << "ID found " << id << " & its a visitor" << endl;

        Attraction atraccion1("rana", 12, 12.4);
        cout << "the name of the attraction is " << atraccion1.getName();


    } else {

        //SI NO ES UN VISITOR COMPROBAR SI ES UN ADMIN
        
        std::cout << "No se encontró el elemento con id: " << id << endl;
    }

    

    return 0;

}
