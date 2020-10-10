// https://www.hackerrank.com/challenges/attending-workshops/problem

#include <bits/stdc++.h>

#include <vector>
#include <algorithm>

using namespace std;


struct Workshop {
    public:
        int start_time;
        int duration;
        int end_time;
        Workshop(int st, int d): start_time(st), duration(d){end_time = start_time + duration;};
        Workshop() = default;
};


struct Available_Workshops {
    public:
        int n;
        Workshop* arr_workers;
        Available_Workshops(int n_wor): n(n_wor), arr_workers(new Workshop[n_wor]) {};
        ~Available_Workshops() {delete [] arr_workers;};
};


Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* av = new Available_Workshops(n);
    for (int i = 0; i < n; ++i){
        av->arr_workers[i] = Workshop(start_time[i], duration[i]);
    }
    return av;
};


int CalculateMaxWorkshops(Available_Workshops* a_workshops){
    vector<pair<int, int> > timetable {};
    for (int i = 0; i < a_workshops->n; ++i){
        pair<int, int> temp = make_pair(a_workshops->arr_workers[i].start_time, 
            a_workshops->arr_workers[i].end_time);
        timetable.push_back(temp);
    }
    sort(timetable.begin(), timetable.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second)
            return a.first > b.first;
        else 
            return a.second < b.second; 
        });

    // removing elements which have the same starting time but are longer than the shortest one
    vector<pair<int, int> > v {timetable.at(0)};
    for (int i = 1; i < timetable.size(); ++i){
        if (timetable.at(i).second != v.back().second)
            v.push_back(timetable.at(i));
    }    
    
    // calculating max number of workshops to attend
    int counter = 0, available = -1;
    for (int i = 0; i < v.size(); ++i){
        if (v.at(i).first >= available){
            ++counter;
            available = v.at(i).second;
            // cout << v.at(i).first << " : " << v.at(i).second << endl;
        } 
    }
    return counter;
}

int main(int argc, char *argv[]) {

    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
