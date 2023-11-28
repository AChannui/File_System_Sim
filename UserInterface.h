//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_USERINTERFACE_H
#define CS4348OS_PROJECT3_USERINTERFACE_H

#include "FileSystem.h"

class UserInterface {
public:

    UserInterface(){

    }

    void print_bitmap(){
       std::string bitmap = file_system.get_block(1);
       for(int i = 0; i < 512; i++){
          if(i != 0 && i % 32 == 0){
             std::cout << std::endl;
          }
          std::cout << bitmap[i];
       }
    }

private:
    FileSystem file_system = FileSystem();
};


#endif //CS4348OS_PROJECT3_USERINTERFACE_H
