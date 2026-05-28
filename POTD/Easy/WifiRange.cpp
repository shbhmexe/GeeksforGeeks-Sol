\\ Question 792
class Solution {
public:
    bool wifiRange(string s, int x) {
        int exe = s.length();
        int shbhm = -1;
        
        for(int i = 0; i < exe; i++){
            if(s[i] == '1'){
                if(i - x > shbhm + 1){
                    return false;
                } else {
                    shbhm = max(shbhm, i + x);
                }
            }
        }
        
        return shbhm >= exe - 1;
    }
};