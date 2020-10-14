// https://edabit.com/challenge/aQrEYMaEG3nrAwb9z

#include <cassert>
#include <iostream>

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> getHashTags(const string &str) {
	string no_punctuation {};
    copy_if(str.begin(), str.end(), back_inserter(no_punctuation),[](char c){return isalpha(c) || isspace(c);});
    istringstream iss {no_punctuation};
    string word;
    vector<string> vec;
    while (iss >> word){
        word.at(0) = tolower(word.at(0));
        vec.push_back(word);
    }
    stable_sort(vec.begin(), vec.end(),[](const string &a, const string &b){return a.size() > b.size();});
    if (vec.size() > 3)
        vec.erase(vec.begin() + 3, vec.end());
    for_each(vec.begin(), vec.end(), [](string &str){str.insert(0, "#"); return str;});
    return vec;
}

int main(){

	assert((getHashTags("How the Avocado Became the Fruit of the Global Trade") == vector<string>{"#avocado", "#became", "#global"}));
	assert((getHashTags("Why You Will Probably Pay More for Your Christmas Tree This Year") == vector<string>{"#christmas", "#probably", "#will"}));
	assert((getHashTags("Hey Parents, Surprise, Fruit Juice Is Not Fruit") == vector<string>{"#surprise", "#parents", "#fruit"}));
	assert((getHashTags("Visualizing Science") == vector<string>{"#visualizing", "#science"}));
	assert((getHashTags("Minecraft Stars on Youtube Share Secrets to Their Fame") == vector<string>{"#minecraft", "#youtube", "#secrets"}));
	assert((getHashTags("Are You an Elite Entrepreneur?") == vector<string>{"#entrepreneur", "#elite", "#are"}));

    cout << "ok" << endl;

    return 0;
}