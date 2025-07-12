class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> m;
        int sum = 0, max_len = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (arr[i] == 0 && sum == 0) {
                max_len = 1;
            }

            if (sum == 0) {
                max_len = i + 1;
            }

            if (m.find(sum) != m.end()) {
                max_len = max(max_len, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }

        return max_len;
    }
};
