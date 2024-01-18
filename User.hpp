// User.hpp
#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>

using namespace std;

class User {
    public:
        User(string name, string id);


        string getName();
        string getId();

        void setName(string name);
        void setId(string id);
        
    private:
        string name;
        string id;
};

#endif // USER_HP