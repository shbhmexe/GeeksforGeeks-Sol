//Question 258
class Solution {
  public:
    int maxSubStr(string str) {
    int ans = 0;
    int sum = 0;
    int n =str.size();
    
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            sum -= 1;
        }
        else
        {
            sum += 1;
        }
        if(sum==0){
            ans++;
        }
    }
    
    if(sum!=0){
        return -1;
    }
    
    return ans;
}
        

};
