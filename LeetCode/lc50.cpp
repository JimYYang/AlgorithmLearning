using LL = long long;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool is_minus = n < 0;
        for (LL k = (LL)abs(n); k; k >>= 1)
        {
            if (k & 1) res *= x;
            x *= x;
        }
        if (is_minus) return 1 / res;
        return res;
    }
};
