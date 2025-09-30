//Question 458
class Solution {
public:
    // Convert decimal number to binary string
    string DecimalToBinary(int num, int length) {
        string result = "";
        while (num > 0) {
            result.push_back((num % 2) + '0'); // convert digit to char
            num /= 2;
        }
        // pad with zeros if needed
        while ((int)result.size() < length) {
            result.push_back('0');
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<string> binstr(int n) {
        vector<string> ans;
        int total = 1 << n; // 2^n combinations
        for (int i = 0; i < total; i++) {
            ans.push_back(DecimalToBinary(i, n));
        }
        return ans;
    }
};