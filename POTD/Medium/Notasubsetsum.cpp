//Question 775
class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int targetSum = 1;
        
        for(int i = 0; i < arr.size(); i++){
            int num = arr[i];
            
            if(num <= targetSum){
                targetSum = targetSum + num;
            }
            if(num > targetSum){
                break;
            }
        }
       return targetSum;
    }
};