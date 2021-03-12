#include <iostream>
#include <gsl/pointers>
#include <gsl/string_span>

#include <iostream>
#include <gsl/gsl>

void process_ints(const gsl::span<const int> s){
    /* using range for loop with gsl::span provides bound checking */
    for (const auto &i : s)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void modify_ints(gsl::span<int> s)
{
    for (int &i : s)
    {
        i *= i;
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    
    std::cout << "Standard solution using pointer and length" << std::endl;
    int j = sizeof(a) / sizeof(a[0]);
    for (size_t i = 0; i < j; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Solution using gsl::span<T>" << std::endl;
    process_ints(a);

    modify_ints(a);
    process_ints(a);   


    return 0;
}