/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11
This contains the tests for the functions in the profile and network class.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define CHECK DOCTEST_CHECK
#include "doctest.h"
#include "profile.h"
#include "network.h"
using namespace std;

TEST_CASE("Task A:"){
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");
    Profile p2("tarma1", "Tarma Roving"); 
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
    Profile p3("Ryj21", "Ryan Jiang");
    CHECK(p3.getUsername() == "Ryj21");
    CHECK(p3.getFullName() == "Ryan Jiang (@Ryj21)");
}

TEST_CASE("Task B:"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("luigi", "Luigi") == true);
    CHECK(nw.addUser("mario", "Mario2") == false);
    CHECK(nw.addUser("mario 2", "Mario2") == false);
    CHECK(nw.addUser("mario-2", "Mario2") == false);

    for(int i = 2; i < 20; i++){
        CHECK(nw.addUser("mario" + to_string(i), "Mario" + to_string(i)) == true);
    }
 
    CHECK(nw.addUser("yoshi", "Yoshi") == false);
    
    Network nw2;
    CHECK(nw2.addUser("luke", "Luke") == true);
    CHECK(nw2.addUser("dave", "Dave") == true);
    CHECK(nw2.addUser("dave", "Davey") == false);
    CHECK(nw2.addUser("luke 2", "Luke2") == false);
    CHECK(nw2.addUser("dave-2", "Dave2") == false);
    CHECK(nw2.addUser("", "") == false);
}

TEST_CASE("Task C:"){
    Network nw1 = Network();
    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");
    nw1.addUser("wario", "Wario");
    CHECK(nw1.follow("mario", "luigi") == true);
    CHECK(nw1.follow("mario", "wario") == true);
    CHECK(nw1.follow("mario", "wario") == true);
    CHECK(nw1.follow("mario", "mario") == false);

    Network nw2 = Network();
    nw2.addUser("luke", "Luke");
    nw2.addUser("dave", "Dave");
    nw2.addUser("jason", "Jason");
    nw2.addUser("michael", "Michael");
    CHECK(nw2.follow("luke", "dave") == true);
    CHECK(nw2.follow("luke", "jason") == true);
    CHECK(nw2.follow("luke", "dave") == true);
    CHECK(nw2.follow("michael", "michael") == false);
}
