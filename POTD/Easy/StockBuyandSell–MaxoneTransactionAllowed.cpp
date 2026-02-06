//Question 722
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
     int mini=prices[0];
    int maxi=0;
    for(int i=1;i<prices.size();i++){
         //check max benefit to sell stock
        if(prices[i]-mini >maxi) maxi=prices[i]-mini;
        //check mini price to buy stock
        if(mini>prices[i]) mini=prices[i];
    }
    return maxi;
    }
};
