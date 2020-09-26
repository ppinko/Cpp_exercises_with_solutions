#pragma once
#ifndef _NBA_H_
#define _NBA_H_

#include <string>
#include <iostream>

using namespace std;

class NBA {
    private:
        string name;
        string team;
    public:
        NBA(string _name, string _team) : name{_name}, team {_team}{};

        // getters
        string get_name() const;
        string get_team() const;

        virtual void introduce() const;

};

#endif