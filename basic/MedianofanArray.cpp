//Question 191'
class Solution {
  public:
    double findMedian(vector<int> &arr) {
       sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n%2==1){
            return arr[n/2];
        }else{
            return (arr[n/2-1]+arr[n/2])/2.0;
        }
        
    }
};