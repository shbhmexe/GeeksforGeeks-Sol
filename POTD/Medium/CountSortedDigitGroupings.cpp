//Question 3
class Solution {
public:
    int DP[105][1000];
    
    int solve(int idx, int prevSum, string& s) {
        if (idx == s.length()) return 1;
        
        if (DP[idx][prevSum] != -1) return DP[idx][prevSum];
        
        int total_ways = 0;
        int curr_sum = 0;
        
     
     
        for (int j = idx; j < s.length(); j++) {
            curr_sum = curr_sum + (s[j] - '0');
            
            if (curr_sum >= prevSum) {
                total_ways = total_ways + solve(j + 1, curr_sum, s);
            }
        }
        
        DP[idx][prevSum] = total_ways;
        return total_ways;
    }

    int validGroups(string &s) {
        for(int i = 0; i < 105; i++) {
            for(int j = 0; j < 1000; j++) {
                DP[i][j] = -1;
            }
        }
        return solve(0, 0, s);
    }
};