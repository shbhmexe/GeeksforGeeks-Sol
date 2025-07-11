// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int ans = arr[n-1] - arr[0];
        int tempmin, tempmax;
        
        for (int i = 1; i < n; i++)  {
            tempmin = min(arr[0] + k, arr[i] - k);
            tempmax = max(arr[n-1] - k, arr[i-1] + k);
            ans = min(ans, tempmax - tempmin);
        }
        return ans;
        
    }
};