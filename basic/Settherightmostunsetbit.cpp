//Question 490
class Solution {
  public:
    int setBit(int n) {
        for(int i = 0 ; i <= 31; i++){
            if(!(n & (1 << i))){
                n = n | ( 1 << i);
                return n;
            }
        }
        return n;
                
    }
};