//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_FILESYSTEM_H
#define CS4348OS_PROJECT3_FILESYSTEM_H

#include <fstream>

#include "Disk.h"


class FileSystem {
public:
    FileSystem() : name_size(8), max_file_blocks(10), disk_size(256){}

    void set_method(int input){
       method = input;
    }

    int get_method() const{
       return method;
    }

    /*
    std::string get_file(const std::string& name) {
       std::vector<int> file_info;
       std::string output;
       int next_block = file_info[0];

       switch(method){
          case 0: // contiguous
            file_info = get_file_start(name);
             for (int i = 0; i < file_info[1]; i++) {
                output.append(disk.read_block(file_info[0] + i));
             }
             break;
          case 1: // chained
            for(int i = 0; i < file_info[1]; i++){
               std::string temp = disk.read_block(next_block);
               temp.resize(block_size - 1);
               output.append(temp);
               next_block = disk.read_block(next_block)[block_size - 1];
            }
            break;
          case 2:
             break;
       }
       return output;
    }
     */

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
       disk.reset_block(index);
       std::string temp = get_block(1);
       temp[index] = '0';
       disk.write_block(1, temp);
    }


    // void delete_file(string name);

/*
    std::vector<int> get_file_start(const std::string& name){
       std::vector<int> output(2,0);
       std::string table = get_block(0);
       if(method == 2){
          for(int i = 0; i < 512; i += name_size + 1){
             if(is_same_name(name, table.substr(i, name_size))){
                output[0] = table[i+name_size];
             }
          }
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
    */

    bool is_same_name(std::string file_name, std::string table_name) const{
       int null_in_table_name = table_name.find('\0');
       if(null_in_table_name != std::string::npos){
          table_name.resize( null_in_table_name);
       }
       return file_name == table_name;
    }

    virtual std::string get_file(const std::string &name) = 0;
    virtual bool is_file_exists(const std::string &name) = 0;
    virtual std::string add_file(const std::string &save_name, const std::string& file_name) = 0;
    virtual void delete_file(const std::string &name) = 0;
    virtual std::vector<std::vector<std::string>> get_table() = 0;


protected:
    int method;
    int name_size;
    int max_file_blocks;
    int disk_size;
    int block_size;
    Disk disk;



};


#endif //CS4348OS_PROJECT3_FILESYSTEM_H
