#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 2 * N;
int h[N], e[M], ne[M], idx, w[M];
int n, m;
int dp[N][N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u, int fa) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        
        if(son == fa) continue;
        
        dfs(son, u);
        
        for (int j = m ; j >= 0; j --) {
            // k等于0时要注意该怎么写
            for (int k = 0; k < j; k ++) {
                dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[son][k] + w[i]);
            }
        }
    }
    
}

int main() {
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n - 1; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 没有树根、不知道边的方向 就需要建立无向树  这样才能保证dfs每个点都能遍历到  无向树需要用fa参数or visited数组
        // 判断是否走回头路
        // 这里价值记录在idx的编号上 这样是因为这个价值不是某一节点的  而是树枝上的  有依赖价值体积都在节点上
        // 建立无向图是因为输入并不一定是父节点到子节点 只是说树枝两端节点的编号
        add(a, b, c);
        add(b, a, c);
    }
    
    dfs(1, -1);
    
    cout << dp[1][m];
    return 0;
}
