//Question 31 june26
class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int , int> freqMap;
        
        for(auto x : arr){
            freqMap[x]++;
        }
        
        vector<vector<int>> ans;
        for(auto pair: freqMap){
            ans.push_back({pair.first, pair.second});
        }
        return ans;
    }
};