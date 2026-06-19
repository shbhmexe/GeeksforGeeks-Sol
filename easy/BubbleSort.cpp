// class Solution {
//   public:
//     void bubbleSort(vector<int>& arr) {
//         // for(int i = 0; i < arr.size(); i++){
//         //     for(int j = i + 1; j < arr.size(); j++){
//         //         if(arr[i] > arr[j]){
//         //             swap(arr[i], arr[j]);
//         //         }
//         //     }
//         // }
//     }
// };

class Solution {
private:
    void bubbleHelper(vector<int>& arr, int n) {
        if (n == 1) {
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }

        bubbleHelper(arr, n - 1);
    }

public:
    void bubbleSort(vector<int>& arr) {
        bubbleHelper(arr, arr.size());
    }
};