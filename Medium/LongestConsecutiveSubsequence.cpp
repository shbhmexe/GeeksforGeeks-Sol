class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        // Step 1: Insert all elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }

        // Step 2: Find the start of a sequence
        for (auto it : st) {
            // Only check if it's the start of the sequence
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};