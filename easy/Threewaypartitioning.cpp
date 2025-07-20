//Question 187

class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        sort(arr.begin(),arr.end());
        int s=arr.size();
        vector<int>ans;
        for(int i=0;i<s;i++)
        {
            if(arr[i]<a)
            {
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<s;i++)
        {
            if(arr[i]>=a && arr[i]<=b)
            {
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<s;i++)
        {
            if(arr[i]>b)
            {
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<s;i++)
        {
           arr[i]=ans[i];
        }
        
    }
};

