class Solution {
  public:
    int minDaysBloom(int m, int k, vector<int> &arr) {
        int n = arr.size();
        if ((long long)m * k > n) return -1;

        auto isPossible = [&](int mid) {
            int count = 0, bouquets = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] <= mid) {
                    count++;
                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
            return bouquets >= m;
        };

        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
