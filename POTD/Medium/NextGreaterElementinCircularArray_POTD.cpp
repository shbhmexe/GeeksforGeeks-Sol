class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int         n = arr.size();             // Size of the array
        vector<int> result(n, -1);              // Result initialized to -1s
        stack<int>  st;                         // Stack to store indices of waiting elements

        for (int i = 0; i < 2 * n; i++) {       // Traverse twice for circularity
            int idx = i % n;                    // Actual index in arr
            int num = arr[idx];                 // Current number

            // While current num is bigger than arr at the top index
            while (!st.empty() && num > arr[st.top()]) {
                result[st.top()] = num;         // Assign it as the next greater
                st.pop();                       // Remove that index
            }

            if (i < n) {                        // Only push original indices on first pass
                st.push(idx);                   // Add index to stack
            }
        }
        return result;                          // Return filled results
    }
};