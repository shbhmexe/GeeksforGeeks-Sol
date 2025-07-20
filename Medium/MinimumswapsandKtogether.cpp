
//Question 188

class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0,j=0,l=0,r=0,maxi=0,count=0,c=0;
        
        while(r<n){
            if(arr[r]<=k){
                count++;
                if(count>maxi){
                    i=l;
                    j=r;
                    maxi=count;
                }
            }
            else{
                count=0;
                l=r+1;
            }
            r++;
        }
        for(int idx=0;idx<n;idx++){
            if(idx>=i && idx<=j) continue;
            if(arr[idx]<=k){
                c++;
            }
        }
        return c;
    }
};