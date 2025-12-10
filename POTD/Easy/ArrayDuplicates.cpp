//Question 611
class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto i : mp){
            int a=i.second;
            if(a>=2){
                a--;
                while(a--){
                     ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};


