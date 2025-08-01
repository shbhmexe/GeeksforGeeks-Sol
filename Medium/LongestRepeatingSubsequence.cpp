//Question 249
class Solution {
public:
    int LongestRepeatingSubsequence(string s) {
        int n = s.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            curr = vector<int>(n + 1, 0);  // Reset current row
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1] && i != j) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;  // Update prev for next iteration
        }

        return prev[n];
    }
};
