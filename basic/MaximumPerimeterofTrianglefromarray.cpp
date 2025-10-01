//Question 433
class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end(), greater<int>());
        
        for(int i=0; i<arr.size()-2; i++){
            if(arr[i+1] + arr[i+2] > arr[i]){
                return arr[i] + arr[i+1] + arr[i+2];
            } else {
                return -1;
            }
        }
    }
};