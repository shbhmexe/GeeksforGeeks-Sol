//Dutch national flag alogo based approach .

// class Solution {
//   public:
//     void sort012(vector<int>& arr) {
//         int n = arr.size();
//         int low = 0, mid = 0, high = n - 1;

//         while (mid <= high) {
//             if (arr[mid] == 0) {
//                 swap(arr[low], arr[mid]);
//                 low++;
//                 mid++;
//             }
//             else if (arr[mid] == 1) {
//                 mid++;
//             }
//             else if (arr[mid] == 2) {
//                 swap(arr[mid], arr[high]);
//                 high--;
//             }
//         }
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    
    obj.sort012(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
