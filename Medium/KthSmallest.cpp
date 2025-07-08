#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // Max-heap to store k smallest elements
        priority_queue<int> maxHeap;

        for (int i = 0; i < arr.size(); i++) {
            maxHeap.push(arr[i]);

            // Keep only k elements in heap
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // The top of the heap is the kth smallest element
        return maxHeap.top();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << sol.kthSmallest(arr, k) << endl;
    return 0;
}



// class Solution {
//   public:
//     // arr : given array
//     // k : find kth smallest element and return using this function
//     int kthSmallest(vector<int> &arr, int k) {
//         // Max-heap to store k smallest elements
//         priority_queue<int> maxHeap;

//         for (int i = 0; i < arr.size(); i++) {
//             maxHeap.push(arr[i]);

//             // Keep only k elements in heap
//             if (maxHeap.size() > k) {
//                 maxHeap.pop();
//             }
//         }

//         // The top of the heap is the kth smallest element
//         return maxHeap.top();
//     }
// };