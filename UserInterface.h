//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_USERINTERFACE_H
#define CS4348OS_PROJECT3_USERINTERFACE_H

#include "ContiguousSystem.h"
#include "FileSystem.h"

class UserInterface {
public:
    UserInterface(){
       bool file_system_picked = false;
       while(!file_system_picked){
          std::cout << "1. contiguous" << std::endl;
          std::cout << "2. chained" << std::endl;
          std::cout << "3. index" << std::endl;
          std::cout << "which file system would you like: ";
          int input;
          std::cin >> input;
          switch(input){
             case 1:
                file_system = ContiguousSystem();
                file_system_picked = true;
                break;
             case 2:
                file_system;
                file_system_picked = true;
                break;

             case 3:
                file_system;
                file_system_picked = true;
                break;

             default:
                std::cout << "Not a valid switch_input. Please try again." << std::endl;
          }
       }
       int switch_input = 0;
       while(switch_input != 8){
          std::cout << "1. display file" << std::endl;
          std::cout << "2. display the file table" << std::endl;
          std::cout << "3. display the bitmap" << std::endl;
          std::cout << "4. display disk block" << std::endl;
          std::cout << "5. copy file out of simulation system" << std::endl;
          std::cout << "6. copy file into simulation system" << std::endl;
          std::cout << "7. delete file" << std::endl;
          std::cout << "8. exit" << std::endl;
          std::cout << "switch_input a number between 1 and 8: ";
          std::cin >> switch_input;

          std::string file_name;

          int block_index;
          switch(switch_input){
             case 1:
                std::cout << "Please input file name: ";
                std::cin >> file_name;
                if(!sanitize_name(file_name)){
                   std::cout << "File name not allowed" << std::endl;
                   break;
                }
                if(!file_system.is_file_exists(file_name)){
                   std::cout << "File not in system" << std::endl;
                   break;
                }


                break;
             case 2:
                break;
             case 3:
                break;
             case 4:
                break;
             case 5:
                break;
             case 6:
                break;
             case 7:
                break;
             case 8:
                break;
             default:
                break;
          }
       }
    }

    void print_table(){
       std::vector<std::vector<std::string>> table = file_system.get_table();
       for(int i = 0; i < table.size(); i++){
          std::cout << table[i][0] << ": " << table[i][1];
          if(table[i].size() > 2){
             std::cout << table[i][2];
          }
          std::cout << std::endl;
       }
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

    void print_file(std::string name){
       std::string file = file_system.get_file(name);
       if(file.find('\0') > 0){

       }
    }

    bool sanitize_name(const std::string& name){
       if(name.size() > 8){
          return false;
       }
       for (char c: name) {
          if (!islower(c)) {
             return false;
          }
       }

       return true;
    }

private:
     ContiguousSystem file_system;
};


#endif //CS4348OS_PROJECT3_USERINTERFACE_H
