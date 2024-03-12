class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            // 注意坐标转换的正确写法
            if (matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[l / m][l % m] == target;
    }
};
