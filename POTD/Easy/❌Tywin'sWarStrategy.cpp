//Question 346
class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int lucky_count = 0;
        vector<int> to_add;

        for (int x : arr) {
            if (x % k == 0) lucky_count++;
            else to_add.push_back(k - (x % k));
        }

        int required = (n + 1) / 2; // ceil(n/2)
        if (lucky_count >= required) return 0;

        sort(to_add.begin(), to_add.end());

        int total_add = 0;
        for (int i = 0; lucky_count < required && i < (int)to_add.size(); i++) {
            total_add += to_add[i];
            lucky_count++;
        }

        return total_add;
    }
};
