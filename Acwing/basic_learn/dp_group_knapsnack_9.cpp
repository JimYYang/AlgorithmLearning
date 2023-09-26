#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int dp[N];
int v[N][N], w[N][N];
int s[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &s[i]);
        
        for(int j = 0; j < s[i]; j ++){
            scanf("%d%d", &v[i][j], &w[i][j]);
            // cout << v[i][j] << " "<< w[i][j] <<endl;
        }
    }
    
    // cout <<endl;
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= 0; j --){ // 这里不写j >= v[i]是因为每组中物品重量不一样
            for(int k = 0; k < s[i]; k ++){
                if(j >= v[i][k])
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
            }
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
