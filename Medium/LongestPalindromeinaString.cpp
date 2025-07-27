//Question 245

class Solution {
  public:
    string longestPalindrome(string &s) {
       int n= s.length();
      std::vector<vector<bool>> lp(n, vector<bool>(n,0));

      int st=0, ml=1;
      for (int d = 0; d < n; ++d)
      {
        for (int i = 0; i < n-d; ++i)
        {
          int j=i+d;

          if(i==j){lp[i][j]=1;}
          else if(j==i+1 && s[i]==s[j]){
            lp[i][j]=1;
            st=i;
            ml=2;
          }
          else if(s[i]==s[j] && lp[i+1][j-1]){
            lp[i][j]=1;
            if(j-i+1>ml){
              st=i;
              ml=j-i+1;
            }
          }
        }
      }
      return s.substr(st,ml);
        
    }
};