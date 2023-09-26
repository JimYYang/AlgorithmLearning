#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int w[N], dp[2][3];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    
    dp[0][2] = 0;
    dp[0][1] = dp[0][0] = -INF;
    
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 2 ; j ++) {
            dp[i & 1][0] = max(dp[i - 1 & 1][0], dp[i - 1 & 1][2] - w[i]);
            dp[i & 1][1] = dp[i - 1 & 1][0] + w[i];
            dp[i & 1][2] = max(dp[i - 1  & 1][2], dp[i - 1 & 1][1]);
        }
    }
    
    printf("%d", max(dp[n & 1][1], dp[n & 1][2]));
    
    return 0;
}
