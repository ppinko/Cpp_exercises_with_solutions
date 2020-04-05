/*
https://edabit.com/challenge/toBkQwkmb94ePzzmX
*/

#include <vector>
#include <string>

bool inBox(std::vector<std::string> arr) {
    int arr_size = arr.size();
    std::string temp;
    if (arr_size <= 2)
        return false;
    else {
        for (int i {1}; i < arr_size - 1; i++){
            for (char c : arr[i]){
                if (c == '#' || c == '*')
                    temp += c;
            }
            if (temp == "#*#")
                return true;
            temp.clear();
        }
    }
	return false;
}

int main(){

    return 0;
}