//Question 195
// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr)
    {
            sort(arr.begin(), arr.end());
            vector<vector<int>> result;
            unordered_set<int> seen;     // to check if -x exists
            set<pair<int, int>> unique;  // to avoid duplicate pairs
        
            for (int num : arr) 
            {
                if (seen.count(-num)) // works only if -ve versionof
                {                                  // +ve integer available 
                    int a = min(num, -num);
                    int b = max(num, -num);
                    unique.insert({a, b});     // ensure sorted pair
                }                                       // automativcally removes dulicates
                seen.insert(num);
            }
        
            for (auto p : unique) {
                result.push_back({p.first, p.second});
            }
        
            return result;
    }
};