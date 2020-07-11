#include <iostream>

int main(){
    char c = getchar();
    bool confirmed;
    switch (c) {
        case 'y':
            confirmed = true;
            break;
        case 'n':
            confirmed = false;
            break;
        default:
            std::cout << "invalid response!\n";
            break;
    }
    if (confirmed) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;    
    return 0;
}