// https://edabit.com/challenge/HQdXY4udvewZH3KX3

#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <utility>
#include <vector>

bool bracketLogic(std::string xp) {
    std::vector<char> buffor {};
    std::map<char, char> m {};
    m.emplace(std::make_pair(char('{'), char('}')));
    m.emplace(std::make_pair(char('['), char(']')));
    m.emplace(std::make_pair(char('('), char(')')));
    m.emplace(std::make_pair(char('<'),char('>')));
    m.emplace(std::make_pair(char('}'), char('X')));
    m.emplace(std::make_pair(char(']'), char('X')));
    m.emplace(std::make_pair(char(')'), char('X')));
    m.emplace(std::make_pair(char('>'),char('X')));
    for (const char& c: xp){
        auto search = m.find(c);
        if (search != m.end() &&  search->second != 'X'){
                buffor.push_back(search->second);
        }
        else if (search != m.end()){
                if (search->first == buffor.back()){
                    buffor.pop_back();
                }
                else return false;
        }
    }
    return (buffor.size() > 0 ? false : true);
}

int main(){
    assert((bracketLogic("{b}{y}{ }[x][{{(t)-}{}](t<w(^)>)-b}<[g](x{u[ ]})y>") == false));
	assert((bracketLogic("{f}[t[[]]<[+](w)t>u(h)(%){f}[d{e}]{c(/)}<w>][v]") == true));
	assert((bracketLogic("[(t)d]</{h}><<a <( )e>[*]{e{e}}<w{x[^]}>>") == false));
	assert((bracketLogic("{g}((-) ^>b)[^]{{*<->}(w)(u)(%)}({/}c)(%)[g{b}]<z({<< >w>c}d)[b]>") == false));
	assert((bracketLogic("(y)(c)(){[[ ]z] [{+}z[*]]{+}}([d]<y<e>>c)[b][b]") == true));
    std::cout << "Success" << std::endl;
    return 0;
}