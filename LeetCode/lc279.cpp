class Solution {
public:
    bool check(int n){
        int r = sqrt(n);
        return r * r == n;
    }
    int numSquares(int n) {
        if (check(n)) return 1;
        for (int a = 1; a <= n / a; a++)
        {
            if (check(n - a * a)) return 2;
        }

        while (n % 4 == 0) n /= 4;
        if (n % 8 != 7) return 3;
        return 4;
    }
};
