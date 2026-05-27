//qUESTION 789
class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();
        int total_zeros = 0;
       
        int left_ones = 0; 
        int left_zeros = 0;
        
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                total_zeros++;
            }
        }
        int toggles = total_zeros;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) left_zeros++;
            if(arr[i] == 1) left_ones++;
            
            int right_zeros = total_zeros - left_zeros;
            
            int curr = left_ones + right_zeros;
            
            if(curr < toggles) 
                toggles = curr;
        }
        
        return toggles;
    }
};