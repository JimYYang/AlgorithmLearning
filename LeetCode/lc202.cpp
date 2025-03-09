class Solution {
public:
    bool isHappy(int n) {
        auto get = [](int x)
        {
            int res = 0;
            while (x)
            {
                res += (x % 10) * (x % 10);
                x /= 10;
            }
            return res;
        };


        int slow = get(n), fast = get(slow);
        while (slow != fast)
        {
            slow = get(slow);
            fast = get(get(fast));
        }
        return slow == 1;
    }
};