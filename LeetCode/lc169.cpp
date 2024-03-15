class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == winner) cnt++;
            else
            {
                if (cnt > 0) cnt--;
                else
                {
                    cnt = 1;
                    winner = nums[i];
                }
            }
        }
        return winner;
    }
};
