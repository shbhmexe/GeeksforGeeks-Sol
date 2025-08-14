//Question 353
// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int left = 0, right = arr.size()-1;
        int mid;
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(arr[mid] > arr[mid+1]) right = mid;
            else left = mid+1;
        }
        return arr[left];
    }
};