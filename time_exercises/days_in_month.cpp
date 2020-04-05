/*
https://edabit.com/challenge/H9nSatiQeDYRDygGa
*/

#include <iostream>

int days(int month, int year) {
	if (month != 2){
		switch (month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: {return 31; break;}
			default : {return 30;}
		}
	}
	else if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
		return 28;
	else
		return 29;
}

int main(){
    std::cout << days(2, 200) << " = 28" << "\n";
    return 0;
}