//
// Created by Alexander Chan-Nui on 11/28/23.
//

#ifndef CS4348OS_PROJECT3_CHAINEDSYSTEM_H
#define CS4348OS_PROJECT3_CHAINEDSYSTEM_H

#include "FileSystem.h"


class ChainedSystem : public FileSystem {
public:
    std::string add_file(const std::string &save_name, const std::string& file_name) {
       std::vector<std::string> blocks;
       std::ifstream file(file_name);
       if (!file.is_open()) {
          return "file not found";
       }
       for (int i = 0; i < max_file_blocks + 1; i++) {
          char buffer[block_size] = {0};
          file.read(buffer, block_size);
          if (file.gcount() == 0) {
             break;
          }
          blocks.push_back(std::string(buffer, block_size));
       }
       if (blocks.size() > max_file_blocks) {
          return "file to large";
       }
       // find start point
       int file_start = save_blocks(blocks.size(), blocks);
       if (file_start < 0) {
          return "not enough disk space";
       }
       add_file_name(save_name, file_start, blocks.size());
       file.close();
       return "file saved";
    }

    void delete_file(const std::string &name) {
       std::vector<int> file_info = get_file_start(name);
       std::string bitmap = disk.read_block(1);
       int index = file_info[0];
       for (int i = 0; i < file_info[1]; i++) {
          std::string block = disk.read_block(index);
          disk.reset_block(index);
          bitmap[index] = '0';
          index = block[block.size() - 1];
       }
       disk.write_block(1, bitmap);
       delete_file_name(name);
    }

    void delete_file_name(const std::string &name) {
       std::string temp = get_block(0);
       for (int i = 0; i < block_size + 1; i += name_size + 2) {
          if (is_same_name(name, temp.substr(i, name_size))) {
             for (int j = 0; j < name_size + 2; j++) {
                temp[i + j] = '\0';
             }
             set_block(0, temp);
             return;
          }
       }
    }

    int save_blocks(int size, std::vector<std::string> blocks) {
       std::string bitmap = get_block(1);
       if (is_enough_space(size, bitmap)) {
          int start = bitmap.find('0');
          int index = bitmap.find('0');
          for (int i = 0; i < size; i++) {
             bitmap[index] = '1';
             std::string temp = blocks[i];
             int next_index = bitmap.find('0', index + 1);
             temp.push_back(next_index);
             disk.write_block(index, temp);
             index = next_index;
          }
          disk.write_block(1, bitmap);
          return start;
       }

       return -1;
    }

    static bool is_enough_space(int size, const std::string &bitmap) {
       int count = 0;
       int index = 2;
       while (count < size) {
          index = bitmap.find('0', index) + 1;
          if (index < 0) {
             return false;
          }
          count++;
       }
       return true;
    }

    void add_file_name(const std::string &name, int start, int size) {
       std::string temp = get_block(0);
       for (int i = 0; i < block_size + 1; i += name_size + 2) {
          if (temp[i] == '\0') {
             for (int j = 0; j < name.size(); j++) {
                temp[i + j] = name[j];
             }
             temp[i + name_size] = start;
             temp[i + name_size + 1] = size;
             break;
          }
       }
       set_block(0, temp);
    }

    std::string get_file(const std::string &name) {
       std::vector<int> file_info = get_file_start(name);
       std::string output;

       int next_block = file_info[0];
       file_info = get_file_start(name);
       for (int i = 0; i < file_info[1]; i++) {
          std::string temp = disk.read_block(next_block);
          output.append(temp.substr(0, temp.size() - 1));
          next_block = temp[temp.size() - 1];
       }
       int temp = output.find('\0');
       if(temp != std::string::npos){
          output.resize(temp);
       }
       return output;
    }

    std::vector<int> get_file_start(const std::string &name) {
       std::vector<int> output(2, 0);
       std::string table = get_block(0);
       for (int i = 0; i < 512; i += name_size + 2) {
          if (is_same_name(name, table.substr(i, name_size))) {
             output[0] = table[i + name_size];
             output[1] = table[i + name_size + 1];
          }
       }
       return output;
    }

    bool is_file_exists(const std::string &name) {
       std::string table = get_block(0);
       for (int i = 0; i < 512; i += name_size + 2) {
          if (is_same_name(name, table.substr(i, name_size))) {
             return true;
          }
       }
       return false;
    }

    std::vector<std::vector<std::string>> get_table() {
       std::vector<std::vector<std::string>> output;
       std::string table = get_block(0);
       for (int i = 0; i < block_size + 1; i += name_size + 2) {
          if (table[i] != '\0') {
             std::string name;
             for (int j = 0; j < name_size; j++) {
                if (table[i + j] == '\0') {
                   break;
                }
                name.push_back(table[i + j]);
             }

             std::vector<std::string> temp;
             output.push_back(temp);
             output[output.size() - 1].push_back(name);
             std::string start_temp(1, table[i + name_size]);
             output[output.size() - 1].push_back(start_temp);
             std::string length_temp(1, table[i + name_size + 1]);
             output[output.size() - 1].push_back(length_temp);
          }
       }
       return output;
    }

private:
    static const int block_size = 511;

};


#endif //CS4348OS_PROJECT3_CHAINEDSYSTEM_H
