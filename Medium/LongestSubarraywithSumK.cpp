class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If prefix sum is exactly k
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Check if there is a subarray (sum - k) already seen
            long long rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Store prefix sum only if not already present
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};