//Question 39
class Solution {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int j = low;

        for (int i = low; i < high; i++) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        
        swap(arr[high], arr[j]);
        return j;
    }
};