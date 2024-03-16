class Solution {
public:
    int get(int n)
    {
        int res = 0;
        while (n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast = get(n);
        int slow = n;
        while (slow != fast)
        {
            fast = get(get(fast));
            slow = get(slow);
        }
        return fast == 1;
    }
};
