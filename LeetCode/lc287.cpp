class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = 0, b = 0;
        while (true)
        {
            a = nums[a];
            b = nums[nums[b]];
            if (a == b)
            {
                a = 0;
                while (a != b)
                {
                    a = nums[a];
                    b = nums[b];
                }
                return a;
            }
        }
        return -1;
    }
};
