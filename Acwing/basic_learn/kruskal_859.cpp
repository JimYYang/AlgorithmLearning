// kruskal 以边为对象

// 用邻接表存储的时候要注意边的数量


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int n, m;

int p[N];

struct Edge{
    int a, b, w;
    bool operator < (const Edge & x)const{
        return w < x.w; //重载sort比较函数的三种方法  重载<   写仿函数  写cmp函数
    }
}edges[N];


int find(int x){
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    
    int a, b, w;
    
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d", &a, &b, &w);
        
        edges[i] = {a, b, w};
    }
    
    sort(edges + 1, edges + 1 + m);
    
    for(int i = 1; i <= n; i ++) p[i] = i; //注意这里是点的并查集
    
    int res = 0, cnt =0;
    
    for(int i = 1; i <= m; i ++){ //从0 开始 排序从头排序即可  从1 开始排序要从1 开始
         a = edges[i].a;
         b = edges[i].b;
         w = edges[i].w;
        
        a = find(a), b = find(b);
        
        if(a != b){
            p[a] = b;
            res += w; 
            cnt ++;
        }
    }
    
    if( cnt !=  n - 1)puts("impossible");
    else printf("%d\n", res);
    return 0;
}

