class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minPrice = INT_MAX;

        for (auto &price : prices)
        {
            res = max(res, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return res;
    }
};
