#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <iterator>

int main(){
    std::string test_str {"Pawel work in Nokia"};

    // toupper() and tolower()
    for(int i {0}; i < test_str.length(); i++)
        test_str[i] = std::toupper(test_str[i]);
    std::cout << "toupper : " << test_str << std::endl;

    // INSERT
    test_str.insert(5, ":)");
    std::cout << "INSERT 1 : " << test_str << std::endl;

    test_str.insert(7, 3, '!');
    std::cout << "INSERT 2 : " << test_str << std::endl;

    std::string success {"success"};
    test_str.insert(test_str.begin()+7, success.begin(), success.end());
    std::cout << "INSERT 3 : " << test_str << std::endl;

    // find - if we use 'int' and there is no substring than it return -1
    int x = test_str.find("world"); 
    std::cout << "Work was found at position : " << x << std::endl; // -1

    // find (siz_t) - if not found it return std::string::npos
    size_t y = test_str.find("world");  
    if (y == std::string::npos) 
        std::cout << "Return std::string::npos" << std::endl;

    // find from algorithms
    auto tak = std::find(test_str.begin(), test_str.end(), 'w');
    if (tak != test_str.end()){
        std::cout << "YEAP found at position " << (tak - test_str.begin())<<  std::endl;

    } else
        std::cout << "NOT FOUND" << std::endl;
    
    // tostring for int and floating point
    double f = 23.43;
    std::string f_str = std::to_string(f);
    std::cout << "Conversion from float to string " << f << '\n';

    // conversion str to unsigned int and floating point
    std::string i1_str {"-11"};
    int i1 = std::stoul(i1_str);
    std::cout << "Conversion from string to int " << i1 << '\n';

    int i2 {};
    std::string test_int {"pawel5"};
    std::string temp_int {};
    for (auto letter : test_int){
        if (std::isdigit(letter)){                  // finding int with std::isdigit()
            temp_int = std::to_string(letter);      // converting to str with std::to_string()
            i2 = std::stoul(temp_int);              // converting to int from string
            break;
        }
    }

    std::string test_concat = "Pawel";
    test_concat += '!';
    std::cout << "Posible to add char to a string: " << test_concat << std::endl;
    test_concat += "#";
    std::cout << "Posible to add string to a string: " << test_concat << std::endl;

    // Using getline to create string
    // std::string GETline {};
    // std::getline(std::cin, GETline);
    // std::cout << GETline << std::endl;

    const unsigned  desired_length(8);
    std::string long_string( "Where is the end?" );
 
    // Shorten with resize( int )
    std::cout << "Before: \"" << long_string << "\"\n";
    long_string.resize( desired_length );
    std::cout << "After: \"" << long_string <<  "\"\n";
    
    // using substring to generate new string
    std::string test_subs {"ANACONDA"};
    std::string sub_str = test_subs.substr(2, 3);     
    // start at 2 index and give 3 element, when second number not given all provided
    std::cout << "Substring of test_subs: " << sub_str << std::endl;

    // replace function (begin, end,)
    std::string str("The quick brown fox jumps over the lazy dog.");
 
    str.replace(10, 5, "red"); // start at position 10 and remove 5 element and replace them with "red"
    str.replace(str.begin(), str.begin() + 3, 5, 'X'); // USING Constructor
    std::cout << str << '\n';

    // append

    std::basic_string<char> str3 = "string"; 
    std::string output;
 
    // 1) Append a char 3 times. 
    // Notice, this is the only overload accepting chars.
    output.append(3, '*');
    std::cout << "1) " << output << "\n";   // 1) ***
 
    //  2) Append a whole string
    output.append(str3);
    std::cout << "2) " << output << "\n";   // 2) ***string
 
    // 3) Append part of a string (last 3 letters, in this case) // 3) ***stringing
    output.append(str3, 3, 3);
    std::cout << "3) " << output << "\n";


    // conversion to C-style strine str.c_str()
    std::string Cpp_str {"Pawel"};
    const char* C_str = Cpp_str.c_str();
    
    // pop_back() and push_back(char ) PUSH BACK ONLY CHARACHTER
    std::string pop_push {"nokia"};
    pop_push.pop_back();
    std::cout << "pop_back : " << pop_push << std::endl;
    pop_push.push_back('A');
    std::cout << "push_back : " << pop_push << std::endl;

    // ERASE
    std::string s_er = "This is an example";
    std::cout << s_er << '\n';
 
    s_er.erase(0, 5); // Erase "This "      // WHEN WE PROVIDE INTS (start, how many to erase)
    std::cout << s_er << '\n';
 
    s_er.erase(std::find(s_er.begin(), s_er.end(), ' ')); // Erase ' ' // WHEN POINTER ERASE ONLY ONE ELEMENT
    std::cout << s_er << '\n';
 
    s_er.erase(s_er.find(' ')); // Trim from ' ' to the end of the string // WITH NUMBER ERASE UP TO THE END
    std::cout << s_er << '\n';


    return 0;
}
