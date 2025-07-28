//Question 271
class Solution {
public:
    string convertToRoman(int n) {
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        int i = 0;
        while (n > 0) {
            while (n >= val[i]) {
                n -= val[i];
                result += sym[i];
            }
            i++;
        }
        return result; // <- Fixed here
    }
};
