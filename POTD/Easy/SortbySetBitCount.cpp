//Question 751
class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
    int n = arr.size();
        vector<pair<int, pair<int,int>>> nums(n);
        
        for (int i=0; i<n; i++) {
            int bits = __builtin_popcount(arr[i]);
            
            nums[i] = {bits, {i, arr[i]}};
        }
        
        
        sort(begin(nums), end(nums), [&](auto& a, auto& b){
            
            if (a.first == b.first) {
                return a.second.first < b.second.first;
            }
            
            return a.first > b.first;
        });
        
        for (int i=0; i<n; i++) {
            arr[i] = nums[i].second.second;
        }
        
        
        return arr;
    }
};

