// 有向无环图才有拓扑排序


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int idx, h[N], e[N], ne[N];
int tt = -1, hh, q[N], d[N];

int n, m;


void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool top_sort(){
    for(int i = 1; i <= n; i ++){
        if(!d[i])q[++ tt] = i;
    }
    
    while(hh <= tt){
        int cur = q[hh ++];
        for(int i = h[cur]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]) q[++ tt] = j;
        }
    }
    
    return tt == n - 1;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    
    int a, b;
    for(int i = 0; i < m; i ++){
        scanf("%d%d", &a, &b);
        
        insert(a, b);
        d[b] ++;
    }
    
    if(top_sort()){
        for(int i = 0; i <= tt; ++i)printf("%d ", q[i]);
    }
    else puts("-1");
    
}
