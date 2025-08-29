//Question 391
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int n = s.length();
        map<char, int> mp;

        // Build frequency map for string p
        for (char &ch : p) {
            mp[ch]++;
        }

        int requiredCount = p.length();
        int i = 0, j = 0;
        int minStart = 0;
        int minWindow = INT_MAX;

        while (j < n) {
            char ch_j = s[j];
            if (mp[ch_j] > 0)
                requiredCount--;

            mp[ch_j]--;

            // Try to shrink the window
            while (requiredCount == 0) {
                if (minWindow > j - i + 1) {
                    minWindow = j - i + 1;
                    minStart = i;
                }

                char ch_i = s[i];
                mp[ch_i]++;
                if (mp[ch_i] > 0)
                    requiredCount++;
                i++;
            }
            j++; // expand the window
        }

        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};
