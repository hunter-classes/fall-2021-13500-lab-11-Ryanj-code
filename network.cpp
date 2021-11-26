#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

Network::Network(){
  numUsers = 0;
  for(int i = 0; i < MAX_USERS; i++){
    for(int j = 0; i < MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

int Network::findID(std::strng usrn){
  for(int i = 0; i < MAX_USERS; i++){
    if(profiles[i].getUsername() == usrn){
      return i;
    }
  }

  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
  
}
