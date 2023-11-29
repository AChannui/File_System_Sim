//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_USERINTERFACE_H
#define CS4348OS_PROJECT3_USERINTERFACE_H
#include <fstream>
#include <iostream>

#include "ChainedSystem.h"
#include "ContiguousSystem.h"
#include "FileSystem.h"
#include "IndexSystem.h"

class UserInterface {
public:
    UserInterface(FileSystem *input_system) : file_system(input_system){
       int switch_input = 0;
       while(switch_input != 8){
          std::cout << std::endl;
          std::cout << "1. display file" << std::endl;
          std::cout << "2. display the file table" << std::endl;
          std::cout << "3. display the bitmap" << std::endl;
          std::cout << "4. display disk block" << std::endl;
          std::cout << "5. copy file out of simulation system" << std::endl;
          std::cout << "6. copy file into simulation system" << std::endl;
          std::cout << "7. delete file" << std::endl;
          std::cout << "8. exit" << std::endl;
          std::cout << "Input a number between 1 and 8: ";
          std::cin >> switch_input;
          std::cout << std::endl;

          std::string output_file_name;
          std::string input_file_name;
          std::string output;
          int block_index;
          switch(switch_input){
             case 1:
                std::cout << "Please input file name: ";
                std::cin >> output_file_name;
                std::cout << std::endl;
                if(!sanitize_name(output_file_name)){
                   std::cout << "File name not allowed" << std::endl;
                   break;
                }
                if(!file_system->is_file_exists(output_file_name)){
                   std::cout << "File not in system" << std::endl;
                   break;
                }
                output = file_system->get_file(output_file_name);
                std::cout << output << std::endl;
                break;

             case 2:
                print_table();
                break;

             case 3:
                print_bitmap();
                break;

             case 4:
                std::cout << "Please input block index: ";
                std::cin >> block_index;
                std::cout << std::endl;
                if(block_index > 255 || block_index < 0){
                   std::cout << "number out of bounds" << std::endl;
                }
                std::cout << file_system->get_block(block_index) << std::endl;
                break;

             case 5:
                std::cout << "Please input copy from file name: ";
                std::cin >> output_file_name;
                std::cout << std::endl;
                std::cout << "Please input copy to file name: ";
                std::cin >> input_file_name;
                std::cout << std::endl;
                if(!sanitize_name(output_file_name)){
                   std::cout << "File name not allowed" << std::endl;
                   break;
                }
                if(!file_system->is_file_exists(output_file_name)){
                   std::cout << "File not in system" << std::endl;
                   break;
                }
                {
                   std::ofstream output_file(input_file_name);
                   if(!output_file.is_open()){
                      std::cout << "Couldn't open output file" << std::endl;
                      break;
                   }
                   output_file << file_system->get_file(output_file_name);
                }
                break;

             case 6:
                std::cout << "Please input copy from file name: ";
                std::cin >> input_file_name;
                std::cout << std::endl;
                std::cout << "Please input copy to file name: ";
                std::cin >> output_file_name;
                std::cout << std::endl;
                if(!sanitize_name(output_file_name)){
                   std::cout << "File name not allowed" << std::endl;
                   break;
                }
                if(file_system->is_file_exists(output_file_name)){
                   std::cout << "File already has that name" << std::endl;
                   break;
                }
                std::cout << file_system->add_file( output_file_name, input_file_name);
                break;

             case 7:
                std::cout << "Please input file name: ";
                std::cin >> output_file_name;
                std::cout << std::endl;
                if(!sanitize_name(output_file_name)){
                   std::cout << "File name not allowed" << std::endl;
                   break;
                }
                if(!file_system->is_file_exists(output_file_name)){
                   std::cout << "File not in system" << std::endl;
                   break;
                }
                file_system->delete_file(output_file_name);
                break;

             case 8:
                return;
             default:
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input" << std::endl;
                break;
          }
       }
    }

    void print_table(){
       std::vector<std::vector<std::string>> table = file_system->get_table();
       for(int i = 0; i < table.size(); i++){
          int size = table[i][1][0];
          std::cout << table[i][0] << ": " << size;
          if(table[i].size() > 2){
             int length = table[i][2][0];
             std::cout << ", " << length;
          }
          std::cout << std::endl;
       }
    }


    void print_bitmap(){
       std::string bitmap = file_system->get_block(1);
       for(int i = 0; i < 512; i++){
          if(i != 0 && i % 32 == 0){
             std::cout << std::endl;
          }
          std::cout << bitmap[i];
       }
       std::cout << std::endl;
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
     FileSystem *file_system;
};


#endif //CS4348OS_PROJECT3_USERINTERFACE_H
