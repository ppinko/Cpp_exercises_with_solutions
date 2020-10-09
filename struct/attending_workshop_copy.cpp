// https://www.hackerrank.com/challenges/attending-workshops/problem

#include<bits/stdc++.h>

using namespace std;

struct Workshop {
    public:
        int start_time;
        int duration;
        int end_time;
        Workshop(int st, int d, int et): start_time(st), duration(d), end_time(et) {};
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

    return ans.arr_workersl
};

int main(int argc, char *argv[]) {

    // 6
    // 1 3 0 5 5 8
    // 1 1 6 2 4 1

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
