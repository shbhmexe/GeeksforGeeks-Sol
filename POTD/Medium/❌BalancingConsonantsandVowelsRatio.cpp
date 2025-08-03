//Question 317
class Solution {
  public:
    int countBalanced(vector<string>& arr) 
    {
        int n=arr.size(), cnt=0;
        vector<int> ps(n,0);
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<arr[i].size(); j++) {
                if(arr[i][j]=='a' || arr[i][j]=='e' || arr[i][j]=='i' || arr[i][j]=='o' || arr[i][j]=='u')
                    ps[i]++;
                else
                    ps[i]--;
            }
        }
        
        for(int i=1; i<n; i++) {
            ps[i]=ps[i]+ps[i-1];
        }
        
        for(int i=0; i<n; i++) {
            if(ps[i]==0)    cnt++;
            
            if(mp.find(ps[i])!=mp.end())
                cnt += mp[ps[i]];
                
            mp[ps[i]]++;
        }
        
        return cnt;
    }
};
