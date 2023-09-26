// 一般有负环  不存在最短路径  但是负环不在要找的那条路径上  就不会影响  此时就有最短路径

// 本题限制了边的个数 所以有负环也可以

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010, inf = 0x3f3f3f3f;

int d[N], memo[N];

int n, m, k;

struct Edge{
    int a, b, w;
}edges[M];

int bellman_ford(){
    memset(d, inf, sizeof d);
    d[1] = 0;
    for(int i = 0; i < k; i ++){
        memcpy(memo, d, sizeof d); // 使用备份来做  每次更新只用上一次的结果
        for(int j = 0; j < m; j ++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            d[b] = min(d[b], memo[a] + w);
        }
    }
    if(d[n] > inf / 2)return inf; // 这样判断  虽然可能到不了 但是距离可能会被更新
    return d[n];
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    
    int a, b, t;
    
    for(int i = 0; i < m; i ++){
        scanf("%d%d%d", &a, &b, &t);
        
        edges[i] = {a, b, t};
    }
    
    int ans = bellman_ford();
    if(ans == inf) puts("impossible");
    else printf("%d\n", ans);
    return 0;
}
