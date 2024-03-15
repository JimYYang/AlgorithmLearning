class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n)
        {
            while (r + 1 < n && nums[r] == nums[r + 1]) r++;
            nums[l++] = nums[r];
            r++;
        }
        return l;
    }
};
