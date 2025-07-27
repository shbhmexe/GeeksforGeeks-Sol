//Question 241
class Solution {
  public:
    int findMaxValue(vector<vector<int>>& a, int n) {
        // Write your code here
        int maxi=INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i+1<n&&j+1<n)
                {
                    maxi=max(maxi,a[i+1][j+1]-a[i][j]);
                }
                
                if(i+1<n) a[i][j]=max(a[i][j],a[i+1][j]);
                if(j+1<n) a[i][j]=max(a[i][j],a[i][j+1]);
                
            }
        }
        
        return maxi;
    }
};