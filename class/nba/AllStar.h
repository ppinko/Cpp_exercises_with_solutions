#pragma once
#ifndef _ALLSTAR_H_
#define _ALLSTAR_H_

#include "NBA.h"

class AllStar : public NBA {
    private:
        string name;
        string team;
    public:
        AllStar(string _name, string _team) : NBA{_name, _team} {};

        virtual void introduce() const override;

};

#endif