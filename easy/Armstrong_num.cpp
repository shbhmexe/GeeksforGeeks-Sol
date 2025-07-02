#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool armstrongNumber(int n) {
        int temp = n;
        int ans = 0;

        while (temp != 0) {
            int digit = temp % 10;
            ans += pow(digit, 3); // Cube of the digit
            temp /= 10;
        }

        return (ans == n);
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (obj.armstrongNumber(n)) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is NOT an Armstrong number." << endl;
    }

    return 0;
}



// class Solution {
// public:
//     bool armstrongNumber(int n) {
//         int temp = n;
//         int ans = 0;

//         while (temp != 0) {
//             int digit = temp % 10;
//             ans += pow(digit, 3); // Cube of the digit
//             temp /= 10;
//         }

//         return (ans == n);
//     }
// };