//Question 720
//question 240

class Solution {
  public:
    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
    int kadanesMin(vector<int>& nums, int n) {
        int sum = nums[0];
        int minSum = nums[0];
        
        for(int i = 1; i < n; i++) {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }
        
        return minSum;
    }
    
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int SUM = accumulate(begin(arr), end(arr), 0);
        
        int minSum = kadanesMin(arr, n);
        int maxSum = kadanesMax(arr, n);
        
        int circSum = SUM - minSum;

        // If all elements are negative, max circular sum will be 0, which is incorrect
        if (maxSum > 0) {
            return max(maxSum, circSum);
        }

        return maxSum;
    }
};
