class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int left = 0;
        for (int i = 0, j; i < n;) // 枚举起点
        {
            for (j = 0; j < n; j++) // 枚举每个起点能往后走多少个加油站
            {
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0) break;
            }
            if (j == n) return i;
            left = 0;
            i = i + j + 1;
        }
        return -1;
    }
};
