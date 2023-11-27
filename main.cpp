#include <iostream>

#include "UserInterface.h"

int main() {

   Block test1;
   test1.set_pointer(100);
   std::cout << test1.get_pointer() << std::endl;
   std::string test1_string = "here is some \0test text\0";
   test1.write_block("here is some test text for test 1. I think this should work but I don't know.");
   std::cout << test1.read_block() << std::endl;
   std::cout << test1.get_pointer() << std::endl;
   std::cout << test1_string << std::endl;
   std::cout << test1_string.size() << std::endl;
   Block test2;
   test2.init_bitmap();
   std::cout << test2.read_block() << std::endl;


   FileSystem system1 = FileSystem(0);

   std::cout << system1.is_same_name("test1", "test") << std::endl;
   std::cout << system1.is_same_name("test1", "test2") << std::endl;
   std::cout << system1.is_same_name("test1", "test if") << std::endl;
   std::cout << system1.is_same_name("test1", "test1") << std::endl;

   system1.set_block(2, "testing writing to a block.");
   std::cout << system1.get_block(2) << std::endl;


   return 0;
}
