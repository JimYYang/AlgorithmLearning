nclude <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;
int dp[N][N], v[N], w[N];
int n, m;
int h[N], e[N], idx, ne[N];

void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u){
    for(int i = v[u]; i <= m; i ++)
        dp[u][i] = w[u];
        
    for(int i = h[u]; i != -1; i = ne[i]){ // 每个子节点代表一组物品  每组物品的体积分布在0-m-v[u] 且一一对应
        int son = e[i];
        
        dfs(son);
        
        for(int j = m; j >= v[son]; j --){
            for(int k = 0; k <= j - v[u]; k ++){
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]); 
            }
        }
    }
}

int main(){
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    int p;
    int root = 1;
    for(int i = 1; i <= n; i ++){
        cin >> v[i] >> w[i] >> p;
        if(p == -1) root = i;
        else
            insert(p, i);
    }
    
    dfs(root);
    
    cout << dp[root][m] << endl;
    return 0;
}
