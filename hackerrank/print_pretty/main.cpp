#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    // Here my code starts


        cout.unsetf(std::ios::uppercase);

        long a = A;
        cout << std::left << std::showbase << std::hex << a << endl;

        cout << std::showpos << std::setprecision(2) << std::fixed;

        cout << std::setw(15) << std::setfill('_') << std::right << B << endl;
    
        cout << std::resetiosflags(std::ios::showpos);
        cout << std::setprecision(9) << std::fixed << std::uppercase << std::scientific << C << endl;

        cout.unsetf(std::ios::scientific | std::ios::uppercase);

    // Here my code ends
	}
	return 0;

}