#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;
int dp[N], que[N], cost[N];
int n, t;

bool check(int limit) {
    int hh = 0, tt = 0;
    
    for (int i = 1; i <= n; i ++) {
        if (hh <= tt && i - limit - 1 > que[hh]) hh ++;
        dp[i] = dp[que[hh]] + cost[i];
        while (hh <= tt && dp[que[tt]] >= dp[i]) tt --;
        que[++ tt] = i;
    }
    
    for (int i = n - limit; i <= n; i ++ ){
        if (dp[i] <= t) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &t);
    
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &cost[i]);
    }
    
    // 二分长度
    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d", r);
    return 0;
}
