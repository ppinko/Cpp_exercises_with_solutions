/*
https://edabit.com/challenge/TpRpsrpbpkHfi5hto

YouTube Video ID Extractor

Given a YouTube URL, extract the video ID and return it as a string.

Examples:

youtubeId("https://www.youtube.com/watch?v=XPEr1cArWRg") ➞ "XPEr1cArWRg"
youtubeId("https://youtu.be/BCDEDi5gDPo") ➞ "BCDEDi5gDPo"
youtubeId("https://youtube.com/watch?t=4m40s&v=vxP3bY-XxY4") ➞ "vxP3bY-XxY4"
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>

std::string youtubeId(std::string link) {
    auto pos_equal = link.find("v=");
	if (pos_equal != std::string::npos){
        auto end = link.substr(pos_equal + 2, link.length() - pos_equal - 2);
        auto pos_at = end.find("&");
        if (pos_at != std::string::npos) return end.substr(0, pos_at);
        return end;
    }
    else {
        auto pos_slash = link.find_last_of("/");
        return link.substr(pos_slash + 1, link.length() - pos_slash - 1);
    }
}


int main(){
    std::cout << std::boolalpha;
    std::cout << youtubeId("https://www.youtube.com/watch?v=XPEr1cArWRg") << std::endl;
    std::cout << youtubeId("https://youtu.be/BCDEDi5gDPo") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}