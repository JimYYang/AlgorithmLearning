// 思想是dp  dp三个参数表示状态  第一个状态不需要  所以是三重循环

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int  N = 210, INF = 0x3f3f3f3f;

int d[N][N];

int n, m, q;

void floyd(){
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &q);
    
    // memset(d, 0x3f, sizeof d);  // 大部分时候不需要初始化为0   但是这题会询问 2 2 这种情况 所以有这种情况时需要用下面的初始化
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j)d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    
    int a, b, w;
    
    while(m --){
        scanf("%d%d%d", &a, &b, &w);
        
        d[a][b] = min(d[a][b], w);
    }
    
    floyd();
    
    while(q--){
        scanf("%d%d", &a, &b);
        if(d[a][b] > 1e9 / 2)puts("impossible");
        else printf("%d\n", d[a][b]);
    }
    return 0;
}
