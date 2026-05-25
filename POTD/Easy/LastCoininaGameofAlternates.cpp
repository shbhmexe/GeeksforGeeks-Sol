//Question 787
class Solution {
  public:
    int coin(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start < end ){
            if(arr[start] > arr[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return arr[start];
        
    }
};