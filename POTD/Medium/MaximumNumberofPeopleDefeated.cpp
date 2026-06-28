class Solution {
  public:
    int maxPeopleDefeated(int p) {
        //O(N)
        // int ans = 0;
        // int i = 1;
        // while(i*i <= p){
        //     p-= i*i;
        //     ans++;
        //     i++;
        // }
        // return ans;
        
        //expected 0(logn) - binary search
        long long s = 0;
        long long e = 100000;
        int ans = 0;
        
        while(s <= e) {
            long long mid = s + (e - s) / 2;
            
            long long srqSum = (mid * (mid + 1) * (2 * mid + 1)) / 6; 
            
            if(srqSum <= p) {
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        
        return ans;
        
    }
};