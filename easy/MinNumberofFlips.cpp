//Question 229
class Solution {
public:
    int minFlips(string S) {
        int count = 0;
       for(int i = 0;i<S.length();i++){
            if(i%2 != 0 && S[i] == '0'){
                  count++;
              }
            else if(i%2 == 0 && S[i] != '0'){
                count++;
               }
       }
      int kcount = 0;
      for(int i = 0;i<S.length();i++){
            if(i%2 != 0 && S[i] != '0'){
                kcount++;
              }
            else if(i%2 == 0 && S[i] == '0'){
                kcount++;
             }
       }
      return min(count,kcount);
   }
};