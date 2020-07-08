// file:///tmp/mozilla_devpyth0/0521-c-practice-exercises-with-solutions.pdf

// What will the following program print?         

#include <iostream>
using namespace std;

int main(){
    
    int a[5] = { 1,2,3,4,5};
    int *p = a+2; // p point to 3
    int *q = new int[3];
    
    int i;
    for(i=0;i<3;i++)                
        *q++ =*p++; // q = p -> {3, 4, 5} both point to 1 val pass 5

    
    cout << "Loop 1" << endl;
    while(p!=a){
        p--;
        cout << p[0] << endl; // out 5 4 3 2, p pointing to 2
    }
    
    cout << "Loop 2" << endl;
    for(i=1;i<=3;i++)
        cout << q[-i] << endl; // out: 5 4 3
    
    delete [] (q-3);
    q=a+1;  // ptr q point to 2
    
    cout << "Loop 3" << endl;
    for(i=0;i<4;i++)
        cout << q[i] << endl; // out: 2 3 4 5

    ++q;

    return 0;
}