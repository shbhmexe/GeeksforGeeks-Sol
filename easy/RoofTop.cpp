//Question 204
class Solution {
  public:
    
    int maxStep(vector<int>& arr) {
        //CodeGenius
        int consecutive_steps=0,maxi=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                consecutive_steps++;
                maxi=max(maxi,consecutive_steps);
            }
            else{
                consecutive_steps=0;
            }
        }
        return maxi;
    }
};
