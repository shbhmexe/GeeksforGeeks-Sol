class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        // Sort based on the starting time
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            // If current interval overlaps with the last interval in ans
            if (arr[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
            else {
                ans.push_back(arr[i]);
            }
        }

        return ans;
        
    }
};