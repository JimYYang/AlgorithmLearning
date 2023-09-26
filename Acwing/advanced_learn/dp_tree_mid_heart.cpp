#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010, M = 2 * N, INF = 0x3f3f3f3f;
int n;
int h[N], e[M], ne[M], w[M], idx;
int down1[N], down2[N], up[N];
int son1[N], son2[N]; // 记录当前节点向下走的最大、次大距离是哪儿儿子更新过来的
// 注意  次大值和最大值（即使相等）一定经过不同的儿子 因为最大距离的儿子的值就是最大值（son2其实不需要）
bool is_leaf[N];
int ans = INF;

// 求出以u为根节点的子树向下走的最大距离
// 这是用子节点更新父节点
int dfs_down(int u, int father) {
    // 这道题如果没有负权边可以在dfs_d时不用设置d1[u]和d2[u]为负无穷，
    // 并且不用特判叶节点，因为d1和d2为零对于更新最大距离没有影响。 
    // 但是如果有负权边就需要用设置为负无穷这种写法，并且也需要特判叶节点
    // 对于本题 每个点都可以视为根节点
    down1[u] = down2[u] = -INF;
    
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        
        int dist = dfs_down(j, u) + w[i];
        
        if (dist >= down1[u]) {
            down2[u] = down1[u];
            down1[u] = dist;
            son2[u] = son1[u]; // 因为此时次大值是之前的最大值
            son1[u] = j; 
        }
        else if (dist > down2[u]) {
            down2[u] = dist;
            son2[u] = j;
        }
    }
    if (down1[u] == -INF) 
        down1[u] = down2[u] = 0, is_leaf[u] = true;
    return down1[u];
}


// 用已经更新得到的父节点的信息更新子节点的信息
void dfs_up(int u, int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        
        if (son1[u] == j) up[j] = max(up[u], down2[u]) + w[i];
        else up[j] = max(up[u], down1[u]) + w[i];
        dfs_up(j, u);
    }
}

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

int main() {
    memset(h, -1, sizeof h);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    dfs_down(1, -1);
    
    dfs_up(1, -1);
    
    ans = down1[1]; // 每个节点都可以当根 根只能向下走  边权为负数时需要这样考虑
    for (int i = 2; i <= n; i ++) 
        if (is_leaf[i]) ans = min(ans, up[i]);
        else
            ans = min(ans, max(up[i], down1[i]));
    printf("%d\n", ans);
    
    return 0;
}
