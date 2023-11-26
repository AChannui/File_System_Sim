//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_BITMAP_H
#define CS4348OS_PROJECT3_BITMAP_H

#include <string>

#include "Block.h"


class Bitmap : Block{
public:
    Bitmap() : block_size(512){
       block.reserve(block_size);
       block[0] = block[1] = 1;
       for(int i = 2; i < block_size; i++){
          block[i] = 0;
       }
    }

    std::string read_block(){
       std::string output = "";
       for(int i = 0; i < block_size; i++){
          output.append(std::to_string(block[i]));
       }
       return output;
    }

private:
    std::vector<int> block;
    int block_size;

};


#endif //CS4348OS_PROJECT3_BITMAP_H
