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

    // for (int i = 0; i <= n; i++)
    //     dp[i][i] = 1;

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (s[i] == s[j])
    //             dp[i][j] = dp[i + 1][j - 1] + 2;
    //         else
    //         {
    //             dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }

    // cout << dp[0][n - 1] << endl;

    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
        dp[i] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        int prev = 1;
        for (int j = i + 1; j < n; j++)
        {
            int cur = dp[j];
            if (s[i] == s[j])
                dp[j] = cur + 2;
            else
            {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = cur;
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}