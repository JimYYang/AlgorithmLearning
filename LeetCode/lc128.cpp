class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;

        for (auto num : nums) hash.insert(num);

        int i = 0, n = nums.size();
        int res = 0;
        for (auto num : nums)
        {
            if (!hash.count(num - 1))
            {
                int right = num;
                while (hash.count(right))
                {
                    hash.erase(right);
                    right++;
                }
                res = max(res, right - num);
            }
        }

        return res;
    }
};