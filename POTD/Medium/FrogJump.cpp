//Question 541
class Solution {
  public:
    
    // dp[i] tells the cost of jumping from i to last step

    
    int solve(int start, int n, vector<int>& height, int prv, vector<int>& dp) {
        if (start >= n) return INT_MAX;
        int cost = abs(height[start] - height[prv]);
        if (dp[start] != -1) return cost+dp[start];
        prv = start;
        int res = min(solve(start+1, n, height, prv, dp), solve(start+2, n, height, prv, dp));
        if (res != INT_MAX) {
            // cout << start << ' ' << res << '\n';
            cost += res;
            dp[start] = res;
        }
        return cost;
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int start = 0;
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(start, n, height, 0, dp);
    }
};