#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
int dp[N][N], v[N], w[N];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
    
    for(int i = n; i >= 1; i --){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = dp[i + 1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][ j - v[i]] + w[i]);
        }
    }
    
    int j = m;
    
    for(int i = 1; i <= n; i ++){
        if(j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]){
            printf("%d ", i);
            j -= v[i];
        }
    }
    
    return 0;
}
