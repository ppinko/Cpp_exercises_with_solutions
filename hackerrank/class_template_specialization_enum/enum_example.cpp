
#include <bits/stdc++.h> 
using namespace std; 
  
// Defining enum Year 
enum year { Jan, 
            Feb, 
            Mar, 
            Apr, 
            May, 
            Jun, 
            Jul, 
            Aug, 
            Sep, 
            Oct, 
            Nov, 
            Dec }; 
            
int main() 
{ 
    int i; 
  
    // Traversing the year enum 
    for (i = Jan; i <= Dec; i++) 
        cout << i << " "; 
  
    return 0; 
} 
