class Solution {
public:
    int nos(int i, int buy, int capacity, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (i == n || capacity == 0)
            return 0;
        if (dp[i][buy][capacity] != -1)
            return dp[i][buy][capacity];
        if (buy == 1) 
            return dp[i][buy][capacity] = max(-prices[i] + nos(i + 1, 0, capacity, prices, n, dp),
                                              0 + nos(i + 1, 1, capacity, prices, n, dp));
        else 
            return dp[i][buy][capacity] = max(prices[i] + nos(i + 1, 1, capacity - 1, prices, n, dp),
                                              0 + nos(i + 1, 0, capacity, prices, n, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return nos(0, 1, 2, prices, n, dp);
    }
};

// class Solution {
//   public:
//     int solve(vector<int>& prices, int k,int i,bool canBuy,vector<vector<vector<int>>>&dp){
//         //base case
//         if(i==prices.size() || k==0 ) return 0;
//         // recursive case
//         if(dp[i][k][canBuy] != -1) return dp[i][k][canBuy];
//         int involve =0, ignore=0;
//         if(canBuy==true){
//             involve=-prices[i] + solve(prices,k,i+1,false,dp);
//             ignore=solve(prices,k,i+1,true,dp);
//         }
//         else{
//             involve=prices[i] + solve(prices,k-1,i+1,true,dp);
//             ignore=solve(prices,k,i+1,false,dp);
//         }
//         return dp[i][k][canBuy]= max(involve,ignore);
//     }
//     int maxProfit(vector<int>& prices, int k) {
//         //CodeGenius
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
//         return solve(prices,k,0,true,dp);
        
//     }
// };
