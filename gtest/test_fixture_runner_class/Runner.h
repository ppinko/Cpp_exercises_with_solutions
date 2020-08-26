#ifndef _RUNNER_H_
#define _RUNNER_H_

#include <string>

using namespace std;

class Runner {
    private:
        string name;
        long distance;
        long time;
    public:
        Runner(string _name, long _distance, long _time);
        ~Runner() = default;

        double get_tempo();

        string getName() const;
        long getDistance() const;
        long getTime() const;

        void setNewTime(const long _time);
        void setNewDistance(const long _distance);
};

#endif