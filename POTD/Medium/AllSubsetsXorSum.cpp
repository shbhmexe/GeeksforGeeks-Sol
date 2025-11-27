//Question 587
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        for(int &arr : arr) {
            result |= arr;
        }

        return result << (n-1);
        
    }
};