#include <iostream>
#include <vector>

using namespace std;

std::vector< std::vector<int> > squarePatch(int n) {
	vector <vector <int> > ans {};
	if (n == 0) {
        return ans;
	}
	for (int i {1}; i <= n; i++) {
        vector <int> temp {};
        for (int j {1}; j <= n; j++) {
            temp.push_back(n);
        }
        ans.push_back(temp);
	}
	return ans;
}

int main(){
    cout << "GOOD" << endl;
    vector <vector <int> > my_ans {squarePatch(3)};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cout << my_ans.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    return 0;
}
