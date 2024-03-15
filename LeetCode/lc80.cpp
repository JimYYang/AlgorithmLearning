class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n)
        {
            int dulp_r = r;
            while (r + 1 < n && nums[r] == nums[r + 1]) r++;
            for (int i = dulp_r; i <= min(dulp_r + 1, r); i++)
                nums[l++] = nums[r];
            r++;
        }
        return l;
    }
};
