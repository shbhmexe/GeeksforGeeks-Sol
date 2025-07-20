//question 185

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int curr_sum = 0, min_len = n + 1;
        int start = 0, end = 0;

        // Use sliding window
        while (end < n) {
            // Expand the window and add elements to curr_sum
            while (curr_sum <= x && end < n) {
                curr_sum += arr[end++];
            }

            // Shrink the window from the left while curr_sum > x
            while (curr_sum > x && start < n) {
                // Update min_len if smaller window is found
                if (end - start < min_len)
                    min_len = end - start;

                // Remove starting element from curr_sum
                curr_sum -= arr[start++];
            }
        }

        // If no valid subarray found, return 0
        return (min_len == n + 1) ? 0 : min_len;
    }
};
