/* 1. 不大于j  f[i] = 0, v >= 0; */
/* 2. 至多为j  f[0] = 0, f[i] = infinite(但是只要控制好循环方向不一定需要初始化) v>= 0; */
/* 3. 至少为j  f[0] = 0, f[i] = infinite(看看具体求什么) v任意 */ 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 22, M = 80;

int dp[N][M];

int n, m, k;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    int v1, v2, w;
    while(k --){
        scanf("%d%d%d", &v1, &v2, &w);

        for(int i = n; i >= 0; i --){
            for(int j = m; j >= 0; j --){
                dp[i][j] = min(dp[i][j], dp[max(0, i - v1)][max(0, j - v2)] + w);
            }
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}
