//Question 37 june26
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j < arr.size() - 1; j++){
                if(arr[i] > arr[j + 1]){
                    swap(arr[i], arr[j + 1]);
                    continue;
                }
            }
        }
    }
};