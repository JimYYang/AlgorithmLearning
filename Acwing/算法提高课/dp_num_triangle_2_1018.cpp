// 加限制的dp问题  labu也有一个讲过 https://mp.weixin.qq.com/s/D-iahj0gSs1UnDv_6KsNWQ
// https://mp.weixin.qq.com/s/4nqJMIyCKQD7IJ-HI6S3Vg

// 限制次数的问题可以抽象为图的问题 转化为限制边数的问题 比如有边数限制的最短路问题 
// 注意审题  第一个格子也需要花费时间

#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 110;

int w[N][N];
int dp[N][N];

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> w[i][j];
    // for(int i = 0; i <= n; i ++)dp[i][0] = dp[0][i] = 1e9;
    
    for(int i = 1; i <= n; i ++){
        dp[1][i] = dp[1][i - 1] + w[1][i];
        dp[i][1] = dp[i - 1][1] + w[i][1];
    }
    
    // 上一题求最大值 所以不把第一行和第一列初始化也可以 因为默认dp[0][...] = d[...][0] = 0 
    // 这一题初始化一下第一行第一列较为方便
    // 也可以在下面的循环里面特判 第一行第一列只能从一个方向走过来
    
    // 有时候求最值还需要初始化为无穷等（看自己写的如何转移）  因为这里没有负数 
    for(int i = 2; i <= n; i ++){
        for (int j = 2; j <= n; j ++ ){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + w[i][j];
        }
    }
    
    cout << dp[n][n] << '\n';
    
    return 0;
}
