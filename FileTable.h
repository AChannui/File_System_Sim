//
// Created by Alexander Chan-Nui on 11/25/23.
//

#ifndef CS4348OS_PROJECT3_FILETABLE_H
#define CS4348OS_PROJECT3_FILETABLE_H

#include "Block.h"

class FileTable : Block{
public:
    FileTable();

    void add_file(std::string Name, int Start, int Size);

    void delete_file(std::string file_name_);

    void print();

private:

};


#endif //CS4348OS_PROJECT3_FILETABLE_H
