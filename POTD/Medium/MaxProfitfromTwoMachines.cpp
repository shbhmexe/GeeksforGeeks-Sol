//Question 763
class Solution {
public:

    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {

        int n = a.size();

        vector<pair<int, int>> arr;

        // Store absolute difference with index
        for (int i = 0; i < n; i++) {
            arr.push_back({abs(a[i] - b[i]), i});
        }

        // Sort in descending order of difference
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        int ans = 0;

        int cntA = 0;
        int cntB = 0;

        for (auto &it : arr) {

            int i = it.second;

            // Prefer A if profit is greater/equal
            if (a[i] >= b[i]) {

                if (cntA < x) {
                    ans += a[i];
                    cntA++;
                }
                else {
                    ans += b[i];
                    cntB++;
                }
            }
            else {

                // Prefer B if profit is greater
                if (cntB < y) {
                    ans += b[i];
                    cntB++;
                }
                else {
                    ans += a[i];
                    cntA++;
                }
            }
        }

        return ans;
    }
};