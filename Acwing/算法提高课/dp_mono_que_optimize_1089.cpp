// 状态转移的时间从O(m)变为O(1)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
int cost[N], dp[N], que[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &cost[i]);
    
    int hh = 0, tt = 0;
    
    for (int i = 1; i <= n; i ++) {
        if (hh <= tt && i - m > que[hh]) hh ++;
        dp[i] = dp[que[hh]] + cost[i];
        while (hh <= tt && dp[que[tt]] >= dp[i]) tt --;
        que[++ tt] = i;
    }
    
    int res = 2e9;
    
    for (int i = n - m + 1; i <= n; i ++) {
        res = min(res, dp[i]);
    }
    
    printf("%d", res);
    return 0;
}
