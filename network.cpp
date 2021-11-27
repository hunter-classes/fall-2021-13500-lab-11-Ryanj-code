#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

Network::Network(){
  numUsers = 0;
  
  for(int i = 0; i < MAX_USERS; i++){
    for(int j = 0; j < MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

int Network::findID(std::string usrn){
  for(int i = 0; i < numUsers; i++){
    if(profiles[i].getUsername() == usrn){
      return i;
    }
  }

  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
  for(int i = 0; i < usrn.size(); i++){
    if(!isalnum(usrn[i])){
      return false;
    }
  }

  if(findID(usrn) != -1){
    return false;
  }

  if(usrn.size() > 0 && numUsers<20){
    profiles[numUsers]=Profile(usrn, dspn);
    numUsers++; 
    return true;
  }

  return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
  if(usrn1 != usrn2 && findID(usrn1) >= 0 && findID(usrn2) >= 0){
    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
  }

  return false;
}

void Network::printDot(){
  std::cout << "digraph {\n";
  for(int i = 0; i < numUsers; i++){
    std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl;
  }

  std::cout << "\n";

  for(int i = 0; i < MAX_USERS; i++){
    for(int j = 0; j < MAX_USERS; j++){
      if(following[i][j]){
	std::cout << "  \"@" << profiles[i].getUsername() << "\" -> \""
		  << "@" << profiles[j].getUsername() << "\"" << std::endl;
      }
    }
  }

  std::cout << "}" << std::endl;
}

