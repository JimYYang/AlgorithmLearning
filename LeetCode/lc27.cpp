class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0, n = nums.size();
        while (r < n)
        {
            if (nums[r] == val)
                r++;
            else
            nums[l++] = nums[r++];
        }
        return l;
    }
};
