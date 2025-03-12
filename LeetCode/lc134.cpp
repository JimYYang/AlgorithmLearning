class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // i每次跳几步是不确定的
        for (int i = 0; i < n;)
        {
            int left = 0;
            int j;
            for (j = 0; j < n; j++)
            {
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0)
                {
                    break;
                }
            }
            if (j == n)
                return i;
            i = i + j + 1;
        }
        return -1;
    }
};