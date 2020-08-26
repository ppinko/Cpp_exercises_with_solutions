#include "Runner.h"

using namespace std;

Runner::Runner(string _name, long _distance, long _time) : name(_name),
    distance(_distance), time(_time) {};

double Runner::get_tempo(){
    double value = 1000 * static_cast<double>(time) / distance;
    return value;
}

string Runner::getName() const {
    return name;
}

long Runner::getDistance() const {
    return distance;
}

long Runner::getTime() const {
    return time;
}

void Runner::setNewTime(const long _time) {
    time = _time;
}

void Runner::setNewDistance(const long _distance) {
    distance = _distance;
}