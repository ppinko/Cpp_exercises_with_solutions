// https://edabit.com/challenge/oe4pzTCSaSMYHG6Kq

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cctype>

std::string correctTitle(std::string str);
void str_lower(std::string* str);

void str_lower(std::string* str){
    std::for_each(str->begin(), str->end(), [](char &c) {c = ::tolower(c);});
}

std::string correctTitle(std::string str) {
    std::set<std::string> s {"of", "the", "and", "in"};
    std::istringstream iss {str};
    std::string answer {};
    std::string temp {};

    while (std::getline(iss, temp, ' ')){
        // std::cout << "TEMP = " << temp << std::endl;
        str_lower(&temp);
        if (temp.find('-') == std::string::npos){
            if (s.count(temp) == 0){
                temp[0] = std::toupper(temp.at(0));
            }
            answer.append(temp);
            answer.push_back(' ');
        }
        else {
            std::istringstream iss2 {temp};
            std::string temp2 {};
            while (std::getline(iss2, temp2, '-')){
                if (s.count(temp2) == 0){
                    temp2[0] = std::toupper(temp2.at(0));
                }
                answer.append(temp2);
                answer.push_back('-');
            }
            answer.erase(answer.size()-1);
        }
    }
    if (answer.at(answer.size() - 1) == ' ')
        answer.erase(answer.size()-1);
    return answer;
}

int main(){

    assert((correctTitle("sansa stark, lady of winterfell.") == "Sansa Stark, Lady of Winterfell."));
	assert((correctTitle("lord eddard stark, hand of the king.") == "Lord Eddard Stark, Hand of the King."));
	assert((correctTitle("jaime lannister, lord commander of the kingsguard.") == "Jaime Lannister, Lord Commander of the Kingsguard."));
	assert((correctTitle("varys, master of whisperers.") == "Varys, Master of Whisperers."));
	assert((correctTitle("doran martell, prince of dorne, lord of sunspear.") == "Doran Martell, Prince of Dorne, Lord of Sunspear."));
	assert((correctTitle("TYRION LANNISTER, HAND OF THE QUEEN.") == "Tyrion Lannister, Hand of the Queen."));
	assert((correctTitle("GRAND MAESTER PYCELLE.") == "Grand Maester Pycelle."));
	assert((correctTitle("EURON GREYJOY, KING OF THE IRON ISLANDS, LORD REAPER OF PYKE.") == "Euron Greyjoy, King of the Iron Islands, Lord Reaper of Pyke."));
	assert((correctTitle("PETYR BAELISH, LORD PROTECTOR OF THE VALE.") == "Petyr Baelish, Lord Protector of the Vale."));
	assert((correctTitle("MANCE RAYDER, KING-BEYOND-THE-WALL.") == "Mance Rayder, King-Beyond-the-Wall."));
    std::cout << "Success" << std::endl;
    return 0;
}