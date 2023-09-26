// 0-i个  以i结尾 i-n个 等等
// 求最 值是可以重复的  只要不漏即可
// 求数量不能有重复 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N]; // 注意 数据类型是经常犯的错误  且不容易被发现
int dp[N][N];


int main(){
    scanf("%d%d", &n, &m);
    
    scanf("%s%s", a + 1, b + 1);
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i] == b[j])dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    printf("%d", dp[n][m]);
    
    return 0;
}
