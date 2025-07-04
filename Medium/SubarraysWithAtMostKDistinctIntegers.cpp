#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAtMostK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0, j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;

            if (mp[arr[j]] == 1) {
                k--;
            }

            while (k < 0) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    k++;
                }
                i++;
            }

            ans += j - i + 1;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    cout << obj.countAtMostK(arr, k) << endl; // Output: Subarrays with at most 2 distinct elements
    return 0;
}


// class Solution {
// public:
//     int countAtMostK(vector<int>& arr, int k) {
//         unordered_map<int, int> mp;
//         int ans = 0;

//         for (int i = 0, j = 0; j < arr.size(); j++) {
//             mp[arr[j]]++;

//             if (mp[arr[j]] == 1) {
//                 k--;
//             }

//             while (k < 0) {
//                 mp[arr[i]]--;
//                 if (mp[arr[i]] == 0) {
//                     k++;
//                 }
//                 i++;
//             }

//             ans += j - i + 1;
//         }
//         return ans;
//     }
// };