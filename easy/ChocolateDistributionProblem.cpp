#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        if (m == 0 || a.size() == 0) {
            return 0;
        }
        
        sort(a.begin(), a.end());
        
        int minDiff = INT_MAX;
        int n = a.size();

        for (int i = 0; i + m - 1 < n; i++) {
            int diff = a[i + m - 1] - a[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};

int main() {
    Solution obj;
    vector<int> chocolates = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    cout << "Minimum Difference: " << obj.findMinDiff(chocolates, m) << endl;

    return 0;
}



// class Solution {
// public:
//     int findMinDiff(vector<int>& a, int m) {
//         if (m == 0 || a.size() == 0) {
//             return 0;
//         }
        
//         sort(a.begin(), a.end());
        
//         int minDiff = INT_MAX;
//         int n = a.size();

//         for (int i = 0; i + m - 1 < n; i++) {
//             int diff = a[i + m - 1] - a[i];
//             minDiff = min(minDiff, diff);
//         }

//         return minDiff;
//     }
// };