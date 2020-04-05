#include <iostream> 

int countPalindromes(int num1, int num2) {
	int counter {0};
    while (num1 <= num2){
        if (num1 <= 9)
            counter++;
        else{
            int n = num1;
            int pal = 0;
            while (n != 0){
                pal = 10 * pal + n % 10;
                n /= 10;
            }
            if (pal == num1)
                counter++;
        }   
        num1++;
    }
    return counter;
}

int main(){
    std::cout << countPalindromes(1, 10) << std::endl;
    std::cout << countPalindromes(555, 556) << std::endl;
    std::cout << countPalindromes(878, 898) << std::endl;
    return 0;
}