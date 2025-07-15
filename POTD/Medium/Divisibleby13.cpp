class Solution {
  public:
    bool divby13(string &s) {
        int nums = 0;
        
        for(int i = 0; i < s.size(); i++){
            nums = (nums * 10 + s[i] -'0') % 13;
        }
        return nums == 0;
    }
};