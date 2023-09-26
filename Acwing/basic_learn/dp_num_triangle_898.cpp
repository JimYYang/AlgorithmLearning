// 考虑dp下标从几开始  and 考虑遍历方向  考虑初始化为什么值
// 考虑边界越界问题（和初始化与从几开始遍历有关）


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n;
int a[N][N];
int dp[N][N];

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <=  i; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    
    
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= i + 1; j ++) //因为有的点不存在左上方或者右上方 所以初始化为负无穷j<=i+1是考虑右上方的情况
            dp[i][j] = -INF; 
    }
    
    dp[1][1] = a[1][1];
    
    
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            dp[i][j] = max(dp[i - 1][ j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
        }
    }
    
    
    int res = -INF;
    
    for(int i = 1; i <= n; i ++)res = max(res, dp[n][i]);
    
    printf("%d\n", res);
    
    return 0;
}
