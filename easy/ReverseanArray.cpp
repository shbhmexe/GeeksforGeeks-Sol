
// class Solution {
// public:
//     void reverseArray(vector<int>& arr) {
//         int s = 0, e = arr.size() - 1;

//         while (s < e) {
//             swap(arr[s], arr[e]);
//             s++;
//             e--;
//         }
//     }
// };


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int s = 0, e = arr.size() - 1;

        while (s < e) {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Before Reverse: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    obj.reverseArray(arr);

    cout << "After Reverse: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
