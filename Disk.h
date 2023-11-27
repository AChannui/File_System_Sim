//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_DISK_H
#define CS4348OS_PROJECT3_DISK_H

#include "Block.h"

class Disk {
public:
    Disk() : disk(256, Block()){
       disk[1].init_bitmap();
    };

    void write_block(int index, const std::string& input){
       disk[index].write_block(input);
    }

    std::string read_block(int index){
       return disk[index].read_block();
    }

private:

    std::vector<Block> disk;

};


#endif //CS4348OS_PROJECT3_DISK_H
