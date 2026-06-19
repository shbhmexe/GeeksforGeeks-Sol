//Question 38 june26
// class Solution {
//   public:
//     void insertionSort(vector<int>& arr) {
//       int n = arr.size();
//         for (int i = 1; i < n; i++) {
//             int key = arr[i];
//             int j = i - 1;
            
//             while (j >= 0 && arr[j] > key) {
//                 arr[j + 1] = arr[j];
//                 j--;
//             }
            
//             arr[j + 1] = key;
//         }
//     }
// };

class Solution {
private:
    void insertionHelper(vector<int>& arr, int n) {
        if (n <= 1) {
            return;
        }

        insertionHelper(arr, n - 1);

        int last = arr[n - 1];
        int j = n - 2;

        while (j >= 0 && arr[j] > last) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = last;
    }

public:
    void insertionSort(vector<int>& arr) {
        insertionHelper(arr, arr.size());
    }
};