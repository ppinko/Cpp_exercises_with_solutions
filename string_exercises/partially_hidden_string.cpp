/*
https://edabit.com/challenge/Zi2zDeQTSdrrFBXiQ
*/

#include <iostream> 
#include <cctype>
#include <string>

std::string partiallyHide(std::string phrase) {
	/*
    - traverse only once through phrase
    - collecting alpha_numeric values
    - when space or end of sentence - ACTION
    */
    std::string replaced {};
    std::string temp {};

    for (int i {0}; i < phrase.length(); i++){
        if (std::isalpha(phrase[i]))
            temp += phrase[i];
        else {
            if (temp.length() > 2){
                std::string dash (temp.length()-2, '-');
                temp.replace(1, temp.length()-2, dash);
            }
            replaced += temp;
            replaced += phrase[i];
            temp = "";            
        }
        if (i == phrase.length() - 1){
            if (temp.length() > 0){
                if (temp.length() > 2){
                    std::string dash (temp.length()-2, '-');
                    temp.replace(1, temp.length()-2, dash);
                }
                replaced += temp;
                temp = "";    
            }
        }
    }
    return replaced;
}

int main (){
    std::cout << partiallyHide("skies were pretty") << " : " << "s---s w--e p----y" << std::endl;
    std::cout << partiallyHide("red is not my color") << " : " << "r-d is n-t my c---r" << std::endl;
    std::cout << partiallyHide("She rolled her eyes") << " : " <<  "S-e r----d h-r e--s" << std::endl;
    return 0;
}