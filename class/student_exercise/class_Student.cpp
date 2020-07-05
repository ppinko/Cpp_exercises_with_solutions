// https://edabit.com/challenges/cpp

#include <iostream>
#include <sstream>

class Student {
    private:
        int age;
        int standard;
        std::string first_name;
        std::string last_name;
    public:
        // setters
        void set_age(const int age){this->age = age;}
        void set_standard(const int standard){this->standard = standard;}
        void set_first_name(const std::string first_name){this->first_name = first_name;}
        void set_last_name(const std::string last_name){this->last_name = last_name;}

        // getters
        int get_age(){return age;}
        int get_standard(){return standard;}
        std::string get_first_name(){return first_name;}
        std::string get_last_name(){return last_name;}
        std::string to_string(){
            std::string answer {std::to_string(age)};
            answer.push_back(',');
            answer.append(first_name);
            answer.push_back(',');
            answer.append(last_name);
            answer.push_back(',');
            answer.append(std::to_string(standard)); 
            return answer;           
            }
};

int main() {
    int age, standard;
    std::string first_name, last_name;
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();
    
    return 0;
}