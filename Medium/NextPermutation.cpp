//Question 220
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        int i = n-1;
        for(; i>0; i--) {
            if(arr[i] > arr[i-1]) {
                break;
            }
        }
        if(i != 0) {
            int index = i;
            for(int j = n-1; j>=i; j--) {
                if(arr[j] > arr[i-1]) {
                    index = j;
                    break;
                }
            }
            swap(arr[i-1], arr[index]);
        }
        reverse(arr.begin()+i, arr
        .end());
        
    }
};