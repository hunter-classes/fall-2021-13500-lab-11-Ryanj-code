/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11
This contains some tests for the functions of the profile and network class.
*/

#include <iostream>
#include "profile.h"
#include "network.h"
using namespace std;

int main(){
    std::cout<<"Task A: \n";
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

    std::cout<<"Task B: \n";
    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    
    for(int i = 2; i < 20; i++)
        std::cout << nw.addUser("mario" + to_string(i), 
                    "Mario" + to_string(i)) << std::endl;   // true (1)

    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;
    

    std::cout<<"Task C: \n";
    Network nw1;
    // add three users
    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");

    //make them follow each other
    nw1.follow("mario", "luigi");
    nw1.follow("mario", "yoshi");
    nw1.follow("luigi", "mario");
    nw1.follow("luigi", "yoshi");
    nw1.follow("yoshi", "mario");
    nw1.follow("yoshi", "luigi");

    nw1.printDot();
    return 0;
}
