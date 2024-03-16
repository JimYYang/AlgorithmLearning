class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 1;
        unordered_map<int, int> cnt;
        cnt[nums[i]]++;
        while (j < n && j <= k)
        {
            if (cnt[nums[j]])
                return true;
            cnt[nums[j]]++;
            j++;
        }

        while (j < n)
        {
            cnt[nums[i]]--;
            i++;
            if (cnt[nums[j]])
                return true;
            cnt[nums[j]]++;
            j++;
        }
        return false;
    }
};
