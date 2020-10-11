#include <iostream>

#include <string>
#include <fstream>

using namespace std;

int main() {

    string f {"/home/devpyth/all/c++/Cpp_exercises_with_solutions/hackerrank/abstract_classes_polymorphism/test_input_2.txt"};
    string o {"/home/devpyth/all/c++/Cpp_exercises_with_solutions/hackerrank/abstract_classes_polymorphism/formatted_output.txt"};

   ifstream in_file;
   in_file.open(f);
   ofstream out_file {o};
   if (in_file){
    //    cout << "inside" << endl;
       string line {};
       while (getline(in_file, line)){
        //    cout << line << endl;
           if (line.substr(0, 3) == "get")
                out_file << line << endl;
       }
   }
   in_file.close();
   out_file.close();
   return 0;
}

