// https://edabit.com/challenge/ZuAiazhSrqsPHqDCg

#include <cmath>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string weHaveHouse(const int hh,const int hw,const int hd,const int rh) {
    if (hh + rh > 20)
        return "No permission.";
    else if (hw > 44 || hd > 44)
        return "House too big.";
    else if (hw < 2 * 4 + 3 + 4 || hd < 2 * 4 + 3)
        return "House too small.";
    else {
        int grey = 2 * 2 * (hw + hd) - 6;
        int under_roof = hw * rh;
        int yellow = 2 * (hh - 2) * (hw + hd) - 3 * 5 - 8 * 4 * 3 + under_roof;
        ostringstream oss; 
        oss << "Yellow: " << yellow << ", Gray: " << grey;
        return oss.str();  
    }
}

int main(){

// {
//   It(test1){Assert::That(weHaveHouse(8, 30, 32, 8), Equals("Yellow: 873, Gray: 242"));}
// 	It(test2){Assert::That(weHaveHouse(10, 31, 30, 11), Equals("No permission."));}
// 	It(test3){Assert::That(weHaveHouse(8, 30, 30, 8), Equals("Yellow: 849, Gray: 234"));}
// 	It(test4){Assert::That(weHaveHouse(9, 20, 18, 8), Equals("Yellow: 581, Gray: 146"));}
// 	It(test5){Assert::That(weHaveHouse(9, 14, 20, 9), Equals("House too small."));}
// 	It(test6){Assert::That(weHaveHouse(8, 16, 12, 8), Equals("Yellow: 353, Gray: 106"));}
// 	It(test7){Assert::That(weHaveHouse(10, 25, 25, 0), Equals("Yellow: 689, Gray: 194"));}
// 	It(test8){Assert::That(weHaveHouse(8, 45, 42, 8), Equals("House too big."));}
// 	It(test9){Assert::That(weHaveHouse(10, 40, 40, 10), Equals("Yellow: 1569, Gray: 314"));}
// 	It(test10){Assert::That(weHaveHouse(10, 15, 10, 7), Equals("House too small."));}
// 	It(test11){Assert::That(weHaveHouse(9, 38, 36, 9), Equals("Yellow: 1267, Gray: 290"));}
// 	It(test12){Assert::That(weHaveHouse(8, 15, 12, 6), Equals("Yellow: 303, Gray: 102"));}
// 	It(test13){Assert::That(weHaveHouse(8, 30, 45, 6), Equals("House too big."));}
// 	It(test14){Assert::That(weHaveHouse(9, 20, 14, 8), Equals("Yellow: 525, Gray: 130"));}
// };

    cout << weHaveHouse(8, 30, 30, 8) << endl;

    return 0;
}