//Question 196

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Temporary vector to store rearranged elements
        int j = 0;
        vector<int> dup(arr.size());

        // First, store all positive elements in 'dup'
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 0) {
                dup[j] = arr[i];
                j++;
            }
        }

        // Next, store all negative elements in 'dup'
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < 0) {
                dup[j] = arr[i];
                j++;
            }
        }

        // Finally, copy back all elements from 'dup' to original 'arr'
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = dup[i];
        }
    }
};
