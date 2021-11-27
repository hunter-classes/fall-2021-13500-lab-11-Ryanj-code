/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11
This is the file with the implementations for the profile class.
*/

#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

Profile::Profile(){
  username = "";
  displayname = "";
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  return displayname + " (@" + username + ")"; 
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}
