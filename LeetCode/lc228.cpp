class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && nums[j] == nums[j - 1] + 1) j++;

            if (j == i + 1) res.push_back(to_string(nums[i]));
            else
            {
                string tmp = to_string(nums[i]);
                tmp += "->";
                tmp += to_string(nums[j - 1]);
                res.push_back(tmp);
            }
            i = j;
        }
        return res;
    }
};
