// 思考当前状态时如何转移过来的
// f[i, j, 0] 已经进行完j次交易
// f[i, j, 1] 正在进行第j次交易 （买入算作交易的开始， 也就是说直到卖出  第j次才完成）
// 初始化考虑好边界即可  有时候不需要初始化那么多值（因为按照一定的循环顺序）
// 但是把边界完整的初始化更容易理解


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 110, INF = 0x3f3f3f3f;
int dp[2][M][2], w[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);

    dp[0][0][1] = -INF;
    dp[1][0][1] = -INF;

    for (int i = 0; i <= m; i ++) dp[0][i][1] = -INF;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            dp[i & 1][j][0] = max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1] + w[i]);
            dp[i & 1][j][1] = max(dp[(i - 1) & 1][j][1], dp[(i - 1) & 1][j - 1][0] - w[i]);
        }
    }

    int ans = 0;

    // 不一定要使用完全部次数 因为交易可能是亏钱的

    for (int i = 0; i <= m; i ++) ans = max(ans, dp[n & 1][i][0]);

    printf("%d", ans);

    return 0;

}
