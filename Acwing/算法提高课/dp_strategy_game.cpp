// 无向图需要判断不能走到父节点（一方面有时候是题目解法的要求 另一方面是dfs的遍历方向）

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1510;
int h[N], e[N], ne[N], idx;
bool has_fa[N];
int dp[N][2];

int n;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}


void dfs(int u) {
    dp[u][1] = 1;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        
        dfs(son);
        
        dp[u][1] += min(dp[son][0], dp[son][1]);
        dp[u][0] += dp[son][1];
    }
}

int main() {
    
    while (scanf("%d", &n) != -1) {
        memset(h, -1, sizeof h);
        idx = 0;
        memset(has_fa, 0, sizeof has_fa);
        memset(dp, 0, sizeof dp);
        
        for (int i = 0; i < n; i ++) {
            int id, cnt;
            scanf("%d:(%d)", &id, &cnt);
            
            while (cnt --) {
                int son;
                scanf("%d", &son);
                has_fa[son] = true;
                add(id, son);
            }
        }
        
        int root = 0;
        while (has_fa[root]) ++ root;
        
        dfs(root);
        
        printf("%d\n", min(dp[root][0], dp[root][1]));
        
    }
    
    return 0;
}
