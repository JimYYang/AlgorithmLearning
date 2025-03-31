#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

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