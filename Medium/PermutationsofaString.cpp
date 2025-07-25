//Question 257
class Solution {
  public:
  
  
    void solve(int i,int n,string &s,string &permu,unordered_set<string> &st){
        if(permu.size()==n){
            st.insert(permu);
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            permu.push_back(s[i]);
            solve(i+1,n,s,permu,st);
            permu.pop_back();
            swap(s[i],s[j]);
            
        }
    }
    vector<string> findPermutation(string &s) {
        // CodeGenius
        unordered_set<string>st;
        string permu;
        int n=s.size();
        solve(0,n,s,permu,st);
        vector<string> result(st.begin(),st.end());
        return result;
    }
};