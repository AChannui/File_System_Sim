//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_FILESYSTEM_H
#define CS4348OS_PROJECT3_FILESYSTEM_H

#include "Disk.h"


class FileSystem {
public:
    FileSystem(int method_) : method(method_), name_size(8){}

    void set_method(int input){
       method = input;
    }

    int get_method() const{
       return method;
    }

    std::string get_file(const std::string& name) {
       std::vector<int> file_info;

       switch(method){
          case 0: // contiguous
            file_info = get_file_start(name);
            for(int i = 0; i < file_info[1]; i++){

            }
            break;

       }
       return "";
    }

    std::string get_block(int index){
      return disk.read_block(index);
    }

    void set_block(int index, const std::string& input){
       disk.write_block(index, input);
       std::string temp = get_block(1);
       temp[index] = '1';
       disk.write_block(1, temp);
    }

    void delete_block(int index){

    }

    // void print_file(string name);

    // void delete_file(string name);


    std::vector<int> get_file_start(const std::string& name){
       std::vector<int> output(2,0);
       std::string table = get_block(0);
       if(method == 2){

       }
       else{
          for(int i = 0; i < 512; i += name_size + 2){
             if(is_same_name(name, table.substr(i, name_size))){
                output[0] = table[i+name_size];
                output[1] = table[i+name_size + 1];
             }
          }
       }
       return output;
    }

    bool is_same_name(std::string file_name, std::string table_name) const{
       for(int i = 0; i < name_size; i++){
          if ((i > file_name.size() - 1 && table_name[i] != '\0') ||
              (file_name[i] != table_name[i])) {
             return false;
          }

       }
       return true;
    }



private:
    int method;
    int name_size;
    Disk disk;



};


#endif //CS4348OS_PROJECT3_FILESYSTEM_H
