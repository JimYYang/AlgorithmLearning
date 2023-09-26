#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e4 + 10;
int dp[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int v;
    dp[0] = 1; // 方案数的问题中 往往dp[0][0] = 1; 表示没选也是一种方案

    for(int i = 0; i < n; i ++){
        scanf("%d", &v);
        for(int j = m; j >= v; j --){
            dp[j] += dp[j - v];
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
