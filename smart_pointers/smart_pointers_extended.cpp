#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Developer {
    private:
        std::string name;
        std::vector<std::string> languages {};
    public:
        Developer(): name{""} {};
        Developer(std::string name_val): name{name_val} {};
        ~Developer(){};
    
        void add_language(const std::string lang) {
            languages.push_back(lang);
        }

        void show_skills() const {
            for (auto& lang: languages)
                std::cout << lang << " ";
            std::cout << std::endl;
        }

        void set_name(const std::string name_val){
            name = name_val;
        }

        void get_name(){
            std::cout << "Developer's name is " << name << std::endl;
        }
};


int main(){

    {   
        std::cout << "without smart pointers\n";
        Developer dev1 {"Pawel"};
        
        dev1.add_language("c++");
        dev1.add_language("python");
        dev1.get_name();
        dev1.show_skills();
    }

    std::vector<std::unique_ptr<Developer>> list_of_developer {}; 

    std::unique_ptr<Developer> dev_ptr1 = std::make_unique<Developer>("Pawel");
    
    dev_ptr1->add_language("c++");
    dev_ptr1->add_language("python");
    dev_ptr1->get_name();
    dev_ptr1->show_skills();

    std::unique_ptr<Developer> dev_ptr2 (new Developer("Paulina"));
    
    dev_ptr2->add_language("bash");
    dev_ptr2->add_language("java");
    dev_ptr2->get_name();
    dev_ptr2->show_skills();

    // list_of_developer.push_back(dev_ptr1); // ERROR - cannot copy smart pointer
    // list_of_developer.push_back(&dev_ptr1); // ERROR - cannot copy smart pointer
    
    list_of_developer.push_back(std::move(dev_ptr1));
    list_of_developer.push_back(std::move(dev_ptr2));

    for (const auto &i : list_of_developer){ // must be passed as referenced, otherwise compiler error
        i->show_skills();
        std::cout << i.get() << std::endl;  // get() - returns an address of unique_ptr
        std::cout << sizeof(i) << std::endl;    // size of unique pointer is 8 bytes
    }

    


    return 0;
}