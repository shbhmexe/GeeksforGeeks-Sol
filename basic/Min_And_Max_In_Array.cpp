#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

class Solution {
public:
    pair<int, int> getMinMax(vector<int>& arr) {
        int n = arr.size();
        
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        
        return {minVal, maxVal};
    }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 2, 9, 1, 7};

    pair<int, int> result = obj.getMinMax(arr);

    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}



// class Solution {
// public:
//     pair<int, int> getMinMax(vector<int>& arr) {
//         int n = arr.size();
        
//         int maxVal = INT_MIN;
//         int minVal = INT_MAX;
        
//         for (int i = 0; i < n; i++) {
//             if (arr[i] > maxVal) {
//                 maxVal = arr[i];
//             }
//             if (arr[i] < minVal) {
//                 minVal = arr[i];
//             }
//         }
        
//         return {minVal, maxVal};
//     }
// };
