class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) s.insert(num);

        int res = 0;
        for (int num : nums)
        {
            if (!s.count(num - 1))
            {
                s.erase(num);
                int y = num;
                while (s.count(y + 1))
                {
                    s.erase(y);
                    y++;
                }
                res = max(res, y - num + 1);
            }
        }
        return res;
    }
};
