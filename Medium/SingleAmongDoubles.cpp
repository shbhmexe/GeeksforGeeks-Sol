// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        int l = 0;
        int h = n-1;
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            bool isEven = (h-mid)%2 == 0;
            
            if(arr[mid] == arr[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    h = mid-1;
                }
            } else {
                if(isEven) {
                    h = mid;
                } else {
                    l = mid+1;
                }
            }
        }
        
        return arr[h];
    }
};