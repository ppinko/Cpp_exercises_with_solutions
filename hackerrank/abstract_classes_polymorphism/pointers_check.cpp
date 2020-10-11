#include <iostream>

using namespace std;

int main(){
    int* a = new int {0};
    int* b = new int {1};
    int* c = new int {2};
    int* d = new int {3};

    int* tail = a;
    int* head = b;
    a = c;
    b = d;
    delete a;
    delete b;

    cout << "a,b,c,d,tail,head " /*<< *a << " "*/ << *b << " " << *c << " " 
        << *d << " " << *tail << " " << *head << endl;  
}