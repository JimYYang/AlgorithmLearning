// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 1010;

// int n, m;

// int v[N], w[N];
// int dp[N][N];

// int main(){
//     scanf("%d%d", &n, &m);
    
//     for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
       
//       dp[0][0-m]为0  这里再全部变量的时候已经初始化了
//     for(int i = 1; i <= n; i ++){
//         for(int j = 0; j <= m; j ++){
//             dp[i][j] = dp[i-1][j];
//             if(j >= v[i])dp[i][j] = max(dp[i][j], dp[i - 1][ j - v[i]] + w[i]);
//         }
//     }
    
//     printf("%d", dp[n][m]);
    
//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;

int v[N], w[N];
int dp[N];

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
    
    for(int i = 1; i <= n; i ++)
    for(int j = m; j >= v[i]; j --){
        dp[j] = max(dp[j], dp[ j - v[i]] + w[i]); // 要使用上一层的  而不是使用本层计算的dp[j - v[i]]
    }
    
    printf("%d", dp[m]);
    
    return 0;
}
