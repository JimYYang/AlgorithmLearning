class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long res = 0;
        int tmp = x;
        while (tmp)
        {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return res == x;
    }
};
