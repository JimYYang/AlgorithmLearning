// prim是以节点为分析对象

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;

int g[N][N], d[N];
bool used[N];

int prim(){
    memset(d, 0x3f, sizeof d);
    
    int res = 0;
    
    for(int i = 0; i < n; i++){
        int t = -1;
        
        for(int j = 1; j <= n; j++){
            if(!used[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        if(i && d[t] == INF)return INF;
        if(i)res += d[t];
        
        for(int j = 1; j <= n; j ++)d[j] = min(d[j], g[t][j]);
        used[t] = true;
    }
    return res;
}

int main(){
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    
    int a, b, w;
    
    while(m --){
        scanf("%d%d%d", &a, &b, &w);
        
        g[a][b] = g[b][a] = min(g[a][b], w);
        
    }
    
    int ans = prim();
    
    if(ans == INF)puts("impossible");
    else printf("%d\n", ans);
    
    return 0;
}






