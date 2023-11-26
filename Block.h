//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_BLOCK_H
#define CS4348OS_PROJECT3_BLOCK_H

#include <iostream>
#include <string>
#include <vector>


class Block {
public:
    Block();

    void set_pointer(int next_block){
       block[block.capacity() - 1] = next_block;
    }

    void set_block(std::string input){
       for(int i = 0; i < input.size(); i++){
          block[i] = input[i];
       }
    }

    int get_pointer(){
       int output = block[block.capacity() - 1];
       return output;
    }

    std::string read_block(){
       std::string output = "";
       for(char c : block){
          output += c;
       }
       return output;
    }

private:
    std::vector<char> block;
};


#endif //CS4348OS_PROJECT3_BLOCK_H
