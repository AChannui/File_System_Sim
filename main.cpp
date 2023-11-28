#include <iostream>

#include "ContiguousSystem.h"

int main() {

   Block test1;
   std::string test1_string = "here is some \0test text\0";
   test1.write_block("here is some test text for test 1. I think this should work but I don't know.");
   std::cout << test1.read_block() << std::endl;
   std::cout << test1_string << std::endl;
   std::cout << test1_string.size() << std::endl;\
   test1.reset_block();


   Block test2;
   test2.init_bitmap();
   std::cout << test2.read_block() << std::endl;


   FileSystem system1 = FileSystem();

   std::cout << system1.is_same_name("test1", "test") << std::endl;
   std::cout << system1.is_same_name("test1", "test2") << std::endl;
   std::cout << system1.is_same_name("test1", "test if") << std::endl;
   std::cout << system1.is_same_name("test1", "test1") << std::endl;

   system1.set_block(2, "testing writing to a block.");
   std::cout << system1.get_block(2) << std::endl;

   ContiguousSystem system2;
   system2.add_file_name("test1", 2, 2);
   system2.set_block(2, "test input for testing getting a file");
   system2.set_block(3, "more test output");
   std::cout << system2.get_block(0) << std::endl;
   std::cout << system2.is_file_exists("test1") << std::endl;
   std::cout << system2.is_file_exists("test2") << std::endl;
   std::cout << system2.get_file("test1") << std::endl;
   std::cout << system2.add_file("sample1") << std::endl;
   std::cout << system2.get_file("sample1") << std::endl;

   std::vector<std::string> testV;
   char *testC = new char[10]{'1', '2', '3'};
   testV.push_back(testC);

   return 0;
}
