// 

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool assessing_rgb(const string &color);
bool validColor(const string &color);
bool assessing_rgba(const string &color);

bool assessing_rgb(const string &color){
    string temp {};
    for (const auto &c : color){
        if (isdigit(c) || c == '%')
            temp += c;
        else if (c == ','){
            if (temp.empty())
                return false;
            int temp_val {};
            if (temp.find('%') == string::npos){
                temp_val = stoi(temp);
                if (temp_val < 0 || temp_val > 255){
                    return false;
                }
            } else {
                temp.pop_back();
                temp_val = stoi(temp);
                if (temp_val < 0 || temp_val > 100){
                    return false;
                }
            }
            temp.clear();
        }         
        else if (!isspace(c))
            return false;
    }
    if (temp.empty())
        return false;
    int temp_val {};
    if (temp.find('%') == string::npos){
        temp_val = stoi(temp);
        if (temp_val < 0 || temp_val > 255){
            return false;
        }
    } else {
        temp.pop_back();
        temp_val = stoi(temp);
        if (temp_val < 0 || temp_val > 100){
            return false;
        }
    }
    return true;
}

bool assessing_rgba(const string &color){
    string temp {};
    for (const auto &c : color){
        if (isdigit(c) || c == '%' || c == '.')
            temp += c;
        else if (!isspace(c))
            return false;
    }
    if (temp.empty())
        return false;
    double temp_val {};
    if (temp.find('%') == string::npos){
        temp_val = stod(temp);
        if (temp_val < 0 || temp_val > 1){
            return false;
        }
    } else {
        temp.pop_back();
        temp_val = stod(temp);
        if (temp_val < 0 || temp_val > 100){
            return false;
        }
    }
    return true;  
}

bool validColor(const string &color) {
	if (color.substr(0, 4) != "rgb(" && color.substr(0, 5) != "rgba("){
        cout << "step 1" << endl;
        return false;
    }
    
    if (color.substr(0, 4) == "rgb("){
        if (count(color.cbegin(), color.cend(), ',') != 2)
            return false;
        auto pos_closing_parenthesis = color.rfind(')');
        if (assessing_rgb(color.substr(4, pos_closing_parenthesis - 4)))
            return true;
        else 
            return false;        
    }

    else if (color.substr(0, 5) == "rgba("){
        if (count(color.cbegin(), color.cend(), ',') != 3)
            return false;
        auto pos_basic_three = color.rfind(',');
        if (!assessing_rgb(color.substr(5, pos_basic_three - 5)))
            return false;
        auto pos_closing_parenthesis = color.rfind(')');
        if (assessing_rgba(color.substr(pos_basic_three + 1, pos_closing_parenthesis - pos_basic_three - 1)))
            return true;
        else 
            return false;               
    }
    return true;
}

int main()
{

    cout << boolalpha;
    cout << validColor("rgba(255,255,255)") << endl;

    return 0;
};