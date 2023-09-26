#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int g[N][N];
int dp[N][N];

int t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> t;
    
    int n, m;
    
    while(t --){
        cin >> n >> m;
        
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cin >> g[i][j];
            }
        }
        
        // memset(dp, 0, sizeof dp); // 多组数据每次数据都要重新初始化 memset不如下面高效
        
        // for (int i = 0; i <= n; i ++ ) // 初始化不是必须的  每次都是从小到大遍历 会被覆盖
        //     for (int j = 0; j <= m; j ++ )
        //         dp[i][j] = 0; 
        
        for(int i = 1; i <= n; i ++)dp[i][1] = g[i][1] + dp[i - 1][1];
        for(int i = 1; i <= m; i ++)dp[1][i] = g[1][i] + dp[1][i - 1]; // 给予适当的初始化 便于理解 这题不初始化也能过
                                                                       // 但需要思考一下边界是否计算正确
        
        for(int i = 2; i <= n; i ++){ // 遍历顺序不需要重新求初始化后的值
            for(int j = 2; j <= m; j ++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
            }
        }
        
        cout << dp[n][m] << '\n';
    }
    return 0;
}
