//Question 498
class Solution {
public:
    vector<int> twoOddNum(vector<int>& Arr) {
        int XOR = 0, no1 = 0, no2 = 0;

        // XOR of all elements
        for (size_t i = 0; i < Arr.size(); i++)
            XOR ^= Arr[i];

        // Get rightmost set bit
        int rightmost = XOR & (~(XOR - 1));

        // Divide numbers into two groups
        for (size_t i = 0; i < Arr.size(); i++) {
            if (Arr[i] & rightmost)
                no1 ^= Arr[i];
            else
                no2 ^= Arr[i];
        }

        // Return in descending order
        if (no1 > no2)
            return {no1, no2};
        else
            return {no2, no1};
    }
};