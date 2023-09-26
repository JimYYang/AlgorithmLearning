#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210;

int w[N], dp[N][N];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> w[i];
        w[i + n] = w[i];
    }
    
    // 求最大值的时候有时初始化为0就够了
    
    for (int len = 3; len <= n + 1; len ++) {
        for (int l = 1; l + len - 1 <= 2 * n; l ++) {
            int r = l + len - 1;
            
            for (int k = l + 1; k < r; k ++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + w[l] * w[k] * w[r]);
            }
        }
    }
    
    int res = 0;
    
    for (int i = 1; i <= n; i ++) res = max(res, dp[i][i + n]);
    
    cout << res << endl;
    return 0;
}
