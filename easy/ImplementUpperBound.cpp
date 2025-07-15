class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int ans = arr.size();
        int low = 0;
        int high = ans - 1;
        int mid;
        
        while(high>=low){
            mid = (low + high)/2;
            
            if(arr[mid]>target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        
        return ans;
        
        // return (upper_bound(arr.begin(),arr.end(),target) - arr.begin());



        
    }
};
