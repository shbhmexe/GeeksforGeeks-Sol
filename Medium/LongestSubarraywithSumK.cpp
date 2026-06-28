//Question 63 june26
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;
        long long currentSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            
            // Condition 1: Shuru se lekar yahan tak ka sum exact 'k' hai
            if (currentSum == k) {
                maxLen = max(maxLen, i + 1);
            }
            
            // Condition 2: Check karo agar (currentSum - k) pehle kabhi dekha hai
            if (mp.find(currentSum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[currentSum - k]);
            }
            
            // Condition 3: Agar currentSum map mein nahi hai, toh index save kar lo
            // (Hum purane index ko overwrite nahi karte taaki length longest rahe)
            if (mp.find(currentSum) == mp.end()) {
                mp[currentSum] = i;
            }
        }
        
        return maxLen;
        
    }
};