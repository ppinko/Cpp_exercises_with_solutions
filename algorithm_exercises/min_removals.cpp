#include <iostream>
#include <algorithm>

int minRemovals(std::string str1, std::string str2) {
	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());
    std::string s2 {};
	std::set_intersection(str1.begin(), str1.end(), str2.begin(),
											 str2.end(), std::back_inserter(s2));
	int k = str1.length() + str2.length() - 2 * s2.length();
	return k;
}

int main(){
    std::cout << minRemovals("deafk", "kfeap") << " = 2" << std::endl;
    return 0;
}