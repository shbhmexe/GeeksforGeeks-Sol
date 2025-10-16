//Question 500
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        set<int> ans;
        for(int i = 1 ; i*i <= n ; i++){
            if(n%i == 0){
                cout << i << " ";
                if(i!=n/i){
                    ans.insert(n/i);
                }
            }
        }
        for(auto it : ans){
            cout << it << " ";
        }
    }
};