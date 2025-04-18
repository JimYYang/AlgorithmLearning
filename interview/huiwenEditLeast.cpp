#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    // 注意是插入 不是修改
    // 这题可以先找最长回文串len  n - len就是答案
    // 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
    // 请你返回让 s 成为回文串的 最少操作次数

    // vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     for (int j = i + 1; j < n; j ++)
    //     {
    //         if (s[i] == s[j])
    //             dp[i][j] = dp[i + 1][j - 1];
    //         else
    //         {
    //             dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
    //         }
    //     }
    // }

    vector<int>dp(n);

    for (int i = n - 2; i >= 0; i--)
    {
        int prev = 0;
        for (int j = i + 1; j < n; j++)
        {
            int cur = dp[j];
            if (s[i] == s[j])
                dp[j] = prev;
            else
            {
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            }
            prev = cur;
        }
    }

    // for (int len = 2; len <= n; len++)
    // {
    //     for (int i = 0; i <= n - len; i++)
    //     {
    //         int j = i + len - 1;
    //         if (s[i] == s[j])
    //         {
    //             dp[i][j] = dp[i + 1][j - 1];
    //         }
    //         else
    //         {
    //             dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
    //         }
    //     }
    // }
    cout << "hhh\n";
    cout << dp[n - 1] << endl;
    return 0;
}