#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1510, INF = 0x3f3f3f3f;
int n;
int h[N], e[N], ne[N], w[N], idx;
bool has_fa[N];
int dp[N][3];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u) {
    dp[u][2] = w[u];
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        
        dfs(son);
        
        dp[u][0] += min(dp[son][1], dp[son][2]);
        dp[u][2] += min(dp[son][0], min(dp[son][1], dp[son][2]));
    }
    
    dp[u][1] = INF;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        
        dp[u][1] = min(dp[u][1], dp[u][0] - min(dp[son][1], dp[son][2]) + dp[son][2]);
    }
}

int main() {
    memset(h, -1, sizeof h);
    
    cin >> n;
    
    for (int i = 1; i <= n; i ++) {
        int id, cnt;
        cin >> id >> w[id] >> cnt;
        
        while (cnt --) {
            int son;
            cin >> son;
            has_fa[son] = true;
            add(id, son);
        }
    }
    
    int root = 1;
    while (has_fa[root]) ++root;
    
    dfs(root);
    
    cout << min((dp[root][0], dp[root][1]), dp[root][2]);
    
    return 0;
}
