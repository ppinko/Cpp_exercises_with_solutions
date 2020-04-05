#include <list>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <iostream>

void display_ls(std::list<int> ls){
    auto it = ls.begin();
    std::cout << "[ ";
    for (it; it != ls.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "]\n"; 
}

int main(){

    // STANDARD FUNCTIONS: l.clear(), l.insert(it, element), l.erase(it), l.push_back(), l.pop_back()
    // l.push_front(), l.pop_front(), l.assign(element), l.front(), l.back()

    std::list<int> ls1 {1, 5, 7, 4, 2};
    display_ls(ls1);
    // UNIQUE - removes duplicates -> ls.unique()
    ls1.sort();                             // SORT -> ls.sort()    // REVERSE -> ls.reverse() 
    display_ls(ls1);
    auto it2 = ls1.begin();                 // auto it = ls.begin() + 3     ERROR!!!!!!!!
    std::advance(it2, 2);                   // std::advance --- POSSIBLE TO MOVE AN ITERATOR
    std::cout << "it2 = " << *it2 << std::endl;

    // REMOVE
    std::list<int> l2 = { 1,100,2,3,10,1,11,-1,12 };
    l2.remove(1);                                   // remove both elements equal to 1
    l2.remove_if([](int n){ return n > 10; });      // remove all elements greater than 10
    display_ls(l2);


    // SPLICE  - to move a part of one list to another
    std::list<int> list1 = { 1, 2, 3, 4, 5 };
    std::list<int> list2 = { 10, 20, 30, 40, 50 };
 
    auto it = list1.begin();
    std::advance(it, 2);
    
    list1.splice(it, list2);    // MOVE ENTIRE LIST
    display_ls(list1);          // [ 1 2 10 20 30 40 50 3 4 5 ]
    display_ls(list2);          // [ ]
    list2.splice(list2.begin(), list1, it, list1.end());    // MOVE A PART OF THE LIST
    display_ls(list1);          // [ 1 2 10 20 30 40 50 ]
    display_ls(list2);          // [ 3 4 5 ]

    // MERGE - lists must be sorted ascending 0 1 2 3 
    // list1.merge(list2);  -> result sorted list
    
    return 0;
}