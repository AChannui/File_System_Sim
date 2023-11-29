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
    Block() : block(512,'\0'){}

    void init_bitmap(){
       block[0] = '1';
       block[1] = '1';
       for(int i = 2; i < 512; i++){
          block[i] = '0';
       }
    }

    void write_block(std::string input){
       for(int i = 0; i < input.size(); i++){
          block[i] = input[i];
       }
    }

    std::string read_block(){
       std::string output;
       for(char c : block){
          output += c;
       }
       return output;
    }

    void reset_block(){
       block = std::vector<char>(512, '\0');
    }

    void test_print(){
       for(char c : block){
          std::cout << c;
       }
       std::cout << std::endl << "finished print" << std::endl;
    }

private:
    std::vector<char> block;
};


#endif //CS4348OS_PROJECT3_BLOCK_H
