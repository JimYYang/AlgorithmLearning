class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist;
        for (auto num : nums) exist.insert(num);
        int res = 0;
        for (auto num : nums)
        {
            if (!exist.count(num - 1))
            {
                int nextNum = num;
                exist.erase(num);
                while (exist.count(nextNum + 1))
                {
                    exist.erase(nextNum + 1);
                    nextNum++;
                }
                res = max(res, nextNum - num + 1);
            }
        }
        return res;
    }
};