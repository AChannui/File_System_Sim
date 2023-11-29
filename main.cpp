#include <iostream>

#include "ContiguousSystem.h"
#include "ChainedSystem.h"
#include "FileSystem.h"
#include "IndexSystem.h"
#include "UserInterface.h"

int main(int argc, const char* argv[]) {

   /*
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




   ContiguousSystem system2;
   system2.add_file_name("test1", 2, 2);
   system2.set_block(2, "test input for testing getting a file");
   system2.set_block(3, "more test output");
   std::cout << system2.get_block(0) << std::endl;
   std::cout << system2.is_file_exists("test1") << std::endl;
   std::cout << system2.is_file_exists("test2") << std::endl;
   std::cout << system2.get_file("test1") << std::endl;
   std::cout << system2.add_file("sample1", "sample") << std::endl;
   std::cout << system2.get_file("sample") << std::endl;
   system2.delete_file("sample");
   std::cout << system2.get_block(1) << std::endl;
   std::cout << system2.get_block(0) << std::endl;
   std::vector<std::vector<std::string>> system2Table = system2.get_table();
   std::cout << system2.get_block(0) << std::endl;


   ChainedSystem system3 = ChainedSystem();
   system3.add_file_name("test1", 2, 1);
   system3.set_block(2, "this is a test of the chained system");
   std::cout << system3.get_file("test1") << std::endl;
   system3.delete_file("test1");
   std::cout << system3.add_file("sample1", "sample") << std::endl;
   std::cout << system3.get_file("sample") << std::endl;
   system3.delete_file("sample");
   std::cout << system3.get_block(1) << std::endl;

   IndexSystem system4;
   std::cout << system4.add_file("sample1", "sample") << std::endl;
   std::string temp = system4.get_file("sample");
   std::cout << temp.find('\0') << std::endl;
   system4.delete_file("sample");

    */

   if(argc < 2){
      std::cout << "wrong arguments" << std::endl;
      return 0;
   }
   FileSystem *system = nullptr;
   std::string file_system_type = argv[1];

   if(file_system_type == "contiguous"){
      system = new ContiguousSystem();
   }
   else if (file_system_type == "chained"){
      system = new ChainedSystem();
   }
   else if(file_system_type == "indexed"){
      system = new IndexSystem();
   }
   else{
      std::cout << "wrong file type argument" << std::endl;
      return 0;
   }
   UserInterface ui(system);

   return 0;
}
