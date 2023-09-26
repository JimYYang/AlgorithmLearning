// 二维dp往往初始化矩形的两个边 还有对角线  且一般只会用到矩阵的一半三角
// 复习labu
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;

int dp[N][N];
char a[N], b[N];

int main(){
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);
    
    for(int i = 1; i <= m; i ++)dp[0][i] = i;
    for(int i = 1; i <= n; i ++)dp[i][0] = i;
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            
            if(a[i] == b[j]){
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else{
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    
    printf("%d", dp[n][m]);
    
    return 0;
}
