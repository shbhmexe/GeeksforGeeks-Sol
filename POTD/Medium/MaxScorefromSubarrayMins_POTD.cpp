#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& arr) {
        int ans = INT_MIN;

        for (int i = 1; i < arr.size(); i++) {
            ans = max(ans, arr[i] + arr[i - 1]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 5, 3, 9, 2};
    
    cout << "Maximum Sum of Adjacent Elements: " << obj.maxSum(arr) << endl;

    return 0;
}


// class Solution {
//   public:
//     int maxSum(vector<int> &arr) {
//         int ans = 0;
        
//         for(int i = 0; i < arr.size(); i++){
//             ans = max(ans, arr[i] + arr[i - 1]);
//         }
//         return ans;
        
//     }
// };