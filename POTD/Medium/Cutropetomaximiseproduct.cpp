//Question 50 june26
class Solution {
public:
    int maxProduct(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int count = n / 3;
        int rem = n % 3;
        
        if (rem == 0) {
            return pow(3, count);
        } else if (rem == 1) {
            return pow(3, count - 1) * 4;
        } else {
            return pow(3, count) * 2;
        }
    }
};