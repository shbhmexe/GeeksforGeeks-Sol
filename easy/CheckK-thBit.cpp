//Question 492
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        //represnet
        string ans="";
        while(n){
            int bit= n&1;
            ans+= (bit + '0');
            n= n>>1;
        }
       
        if(ans.size()<k){
            return false;
        }
        return ans[k]=='1' ? true : false;
    }
};