//Question 499
class Solution {
  public:
    vector<int> primeFac(int n) {
        vector<int> ans;
        int i = 2;
        while(n > 1) {
            if(n % i == 0) {
                n = n / i;
                if(ans.empty() || ans.back() != i)
                    ans.push_back(i);
            }
            else 
                i++;
        }
        
        return ans;
    }
};