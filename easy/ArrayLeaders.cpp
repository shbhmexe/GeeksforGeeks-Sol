class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int maxi = INT_MIN;
        int n = arr.size();
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end()); // maintain the order as in original array
        return ans;
    }
};
