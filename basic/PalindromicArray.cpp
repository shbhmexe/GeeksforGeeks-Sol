//Question 190

/*Complete the function below*/

class Solution {
  public:
    bool isPalinArray(vector<int> &arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int temp = arr[i];
            int x = 0;
            
            while(temp != 0){
                x  = x*10 + (temp % 10);
                temp = temp / 10;
            }
            
            if(x != arr[i]){
                return false;
            }
            
        }
        return true;
        
    }
};