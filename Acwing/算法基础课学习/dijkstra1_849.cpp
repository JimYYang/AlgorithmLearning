// 最短路问题考察的是如何建图 不侧重原理 侧重实践
// 如何将问题抽象成点和边  然后使用最短路算法来做


// dijkstra1  迭代n次 每次更新一个距离 
// 稠密图(m = n^2)用邻接矩阵来存储
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


const int N = 510;

int n, m;
int g[N][N], dist[N];

bool used[N];

// 注意这里节点编号大多从1 开始

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < n; i ++){
        int t = -1;
        
        for(int j = 1; j <= n; j ++)
            if(!used[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        if (t == n)break;
        used[t] = true;
        
        for(int j = 1; j <= n; j ++){ // 其实是遍历所有的边
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main(){
    
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);
    
    int x, y, w;
    while(m --){
        scanf("%d%d%d", &x, &y, &w);
        
        g[x][y] = min(g[x][y], w);
    }
    
    printf("%d", dijkstra());
    return 0;
}
