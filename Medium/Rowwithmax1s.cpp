// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi = 0;
        int index = 0;
        for(int i = 0; i < arr.size(); i++){
            int countOnes = 0;
            for(int j = 0; j < arr[0].size(); j++){
                if(arr[i][j] == 1){
                     countOnes++;
                }
            }
            if(countOnes > maxi){
                maxi = countOnes;
                index = i;
            }
        }
        return index;
        
    }
};