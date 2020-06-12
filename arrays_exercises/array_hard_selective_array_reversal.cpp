/*
https://edabit.com/challenge/yjifZpayEQrQL7SfF
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <iterator>

std::vector<int> selReverse(std::vector<int> arr, int len) {
	int arr_len {static_cast<int>(arr.size())};
    if (len == 0) return arr;
    else if (len >= arr.size()){
        std::reverse(arr.begin(), arr.end());
        return arr;
    }
    else {
        int first = 0;
        int last = len;
        int last_index = len;
        auto it_first = arr.begin();
        auto it_last = arr.begin() + last;
        while (it_last != arr.end()){
            std::reverse(it_first, it_last);
            it_first += last;
            it_last += last;
            last_index += last;
            if (last_index == arr.size()-1){
                std::reverse(it_first, it_last);
                break;
            }
            else if (last_index > arr.size()-1){
                std::reverse(it_first, arr.end());
                break;
            }
        }
    }
    return arr;
}


// Alternative solution

std::vector<int> selReverse(std::vector<int> arr, int len) {

	if(len == 0 || arr.size()==1) return arr;
	
	for(std::vector<int>::iterator iter = arr.begin();
		  iter != arr.end(); iter+=len){
		if((iter+len)!=arr.end())
			std::reverse(iter, iter+len);
		else
			std::reverse(iter, arr.end());
	}
	
	return arr;
}


int main(){
    std::cout << "Success" << std::endl;
    return 0;
}