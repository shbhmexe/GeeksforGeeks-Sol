//Question 2 2026 june
class Solution {
public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        long long exe = 1e9 + 7;
        int zeroCnt = 0;
        int negCnt = 0;
        int maxNeg = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCnt++;
            }
            if (arr[i] < 0) {
                negCnt++;
                maxNeg = max(maxNeg, arr[i]);
            }
        }

        if (zeroCnt == n) return 0;
        if (negCnt == 1 && zeroCnt == n - 1) return 0;

        long long shbhm = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;

            if (negCnt % 2 != 0 && arr[i] == maxNeg) {
                negCnt--;
                continue;
            }
            shbhm = (shbhm * arr[i]) % exe;
        }

        return shbhm;
    }
};