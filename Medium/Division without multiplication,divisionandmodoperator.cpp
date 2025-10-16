//Question 469
class Solution {
public:
    static int divide(long long dividend, long long divisor) {
        long long ans = 0;
        bool sign = (dividend >= 0) == (divisor >= 0);

        long long n = std::llabs(dividend);
        long long d = std::llabs(divisor);

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << cnt)) {
                cnt++;
            }
            cnt--;
            ans += 1LL << cnt;
            n -= (d << cnt);
        }

        ans = sign ? ans : -ans;

        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return static_cast<int>(ans);
    }
};
