class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
       
       int n=arr.size();
       
       unordered_map<int,int>m;
       
       for(int i=1; i<n; i++){
           arr[i]=arr[i]+arr[i-1];
           
       }
        
        for(int i=0; i<n; i++){
            
            if(arr[i]==0) return true;
            
            int rem=arr[i]-0; // k=0
            
            if(m.find(arr[i])!= m.end()) return true;
            
            m[arr[i]]++;
        }
        return false;
    }
};