#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 55, MOD = 1e9 + 7;
int dp[N][N];
char s[N];
int ne[N];

int main() {
    int n;
    scanf("%d%s", &n, s + 1);
    
    int m = strlen(s + 1); // 不要写错 要从s+1开始 这里和排序一样容易出错
    
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) j ++;
        ne[i] = j;
    }
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++) {
            for (char k = 'a'; k <= 'z'; k ++) {
                int u = j;
                
                while (u && k != s[u + 1]) u = ne[u];
                if (k == s[u + 1]) u ++;
                // 本题的更新方法是看当前状态j 可以到达哪些状态（即枚举k 找到每个k对应的u）
                // 然后将自己的方案数(dp[i][j])更新到它自己能到的状态
                // 以往的做法是看有多少其他的状态能到达本状态
                if (u < m) dp[i + 1][u] = (dp[i + 1][u] + dp[i][j]) % MOD;
            }
        }
    }
    
    
    int ans = 0;
    
    for(int i = 0; i < m; i ++) ans = (ans + dp[n][i]) % MOD;
    
    printf("%d", ans);
    
    return 0;
}
