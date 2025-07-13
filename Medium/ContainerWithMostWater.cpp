class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0, j = n-1;
        
        int water = 0;
        while(i<j) {
            
            //start from the smallest one and calculate water
            int h = min(arr[i], arr[j]);
            int w = j-i;
            int area = h*w;
            water = max(water, area);
            
            if(arr[i] < arr[j])
                i++;
            else
                j--;
        }
        
        return water;
    }
};