//Question 9 june26
class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        sort(arr.rbegin(), arr.rend());
        int pairSum = 0;
        
        for(int i = 0; i < arr.size() - 1; i++){
            if((arr[i] - arr[i + 1]) < k){
                pairSum += arr[i] + arr[i+1];
                i++;
            }
        }
        return pairSum;
        
    }
};