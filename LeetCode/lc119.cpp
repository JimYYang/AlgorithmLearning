class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> f;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> line(i + 1);
            line[0] = line[i] = 1;

            for (int j = 1; j < i; j++)
            {
                line[j] = f[i - 1][j - 1] + f[i - 1][j];
            }
            if (i == rowIndex) return line;
            f.emplace_back(line);
        }
        return {};
    }
};
