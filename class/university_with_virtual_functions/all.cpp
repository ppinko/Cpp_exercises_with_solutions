#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <numeric>
using namespace std;

class Person {
    private:
        std::string name;
        int age;
    public:
        Person(std::string name_per, int age_per):
            name{name_per}, age{age_per}{}
        
        Person(): Person("", 0){}

        virtual ~Person(){}
        
        virtual void getdata(){
            std::string name_per;
            int age_per;
            std::cin >> name_per >> age_per;
        }

        std::string getName() const{
            return name;
        }
        
        int getAge() const{
            return age;
        }

        virtual void putdata() const{
            std::cout << getName() << " " << getAge() << std::endl;
        } 

        void set_name(std::string new_name){name = new_name;}

        void set_age(int new_age){age = new_age;}
};

class Professor: public Person {
    private:
        static int id_prof;
        int publications;
        int cur_id;
    public:
        Professor(std::string name_per, int age_per): 
            Person(name_per, age_per), cur_id{id_prof} {id_prof++;}
        
        Professor(): Person("", 0), cur_id{id_prof} {id_prof++;}
        
        virtual ~Professor(){};

        virtual void getdata() override{
            std::string name_prof;
            int age_prof;
            std::cin >> name_prof >> age_prof >> publications;
            set_name(name_prof);
            set_age(age_prof);
        }
        
        virtual void putdata() const override{
            std::cout << getName() << " " << getAge() << " " << publications 
                << " " << cur_id << std::endl;
        } 
};

class Student: public Person {
    private:
        static int id_stud;
        int cur_id;
        std::vector<int> marks;
    public:
        Student(std::string name_per, int age_per): 
            Person(name_per, age_per), cur_id{id_stud} {id_stud++;}
        
        Student(): Person("", 0), cur_id{id_stud} {id_stud++;}

        virtual ~Student(){};

        virtual void getdata() override{
            std::string name_stud;
            int age_stud;
            int a, b, c, d, e, f;
            std::cin >> name_stud >> age_stud >> a >> b >> c >> d >> e >> f;
            set_name(name_stud);
            set_age(age_stud);
            std::vector<int>temp {a, b, c, d, e, f};
            std::copy(temp.begin(), temp.end(), std::back_inserter(marks));
        }

        virtual void putdata() const override{
            int marks_sum = std::accumulate(marks.begin(), marks.end(), 0);
            std::cout << getName() << " " << getAge() << " " << marks_sum  
            << " " << cur_id << std::endl;
        } 

};

int Professor::id_prof = 1;
int Student::id_stud = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
