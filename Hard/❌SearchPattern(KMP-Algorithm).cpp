class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        vector<int>ans;
        size_t pos=txt.find(pat);
        while(pos!=string::npos){
            ans.push_back(pos);
            pos=txt.find(pat,pos+1);
        }
        return ans;
    }
};