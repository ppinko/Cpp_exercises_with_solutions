/*
https://edabit.com/challenge/rsjz5PyvB998zDSHF

Hot Pics of Danny DeVito!

I'm trying to watch some lectures to study for my next exam but I keep getting 
distracted by meme compilations, vine compilations, anime, and more on my favorite
video platform.

Your job is to help me by creating a function that takes in a String and checks 
to see if it contains the following words or phrases:

    "anime"
    "meme"
    "vines"
    "roasts"
    "Danny DeVito"

If it does, return "NO!". Otherwise, return "Safe watching!".
*/

#include <iostream>
#include <vector>
#include <string>

std::string preventDistractions(std::string str) {
	std::vector<std::string> bans {"anime", "meme", "vines", "roasts", "Danny DeVito"};
    for (auto const& word : bans){
        if (str.find(word) != std::string::npos) return "NO!";
    }
    return "Safe watching!";
}

int main(){
    std::cout << preventDistractions("top 10 insert random yt celebrity roasts") << std::endl;
    return 0;
}
