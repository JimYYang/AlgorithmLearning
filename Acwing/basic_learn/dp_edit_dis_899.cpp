#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15, M = 1010;

char str[M][N];
int dp[N][N];


int edit_dis(char a[], char b[]){
    int n = strlen(a + 1), m = strlen(b + 1); // 注意要从1开始 字符数组开的再大  全部默认初始化为'\0'
    
    for(int i = 1; i <= m; i ++)dp[0][i] = i;
    for(int i = 1; i <= n; i ++)dp[i][0] = i; // 注意这里只初始化了边界  并且每次都要初始化
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return dp[n][m];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++)scanf("%s", str[i] + 1);
    char s[N];
    int limit;
    while(m--){
        int res = 0; // 注意res要定义在内部
        scanf("%s%d", s + 1, &limit);
        for(int i = 0; i < n; i ++){
            if(edit_dis(str[i], s) <= limit)
                res ++;
        }
        
        printf("%d\n", res);
    }
    
    return 0;
}
