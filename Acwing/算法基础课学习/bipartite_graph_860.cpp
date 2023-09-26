// 二分图集合内部没有边

// 无向图存储边数为2倍


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int idx, h[M], e[M], ne[M];
int color[N];

void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int u, int c){
    color[u] = c;
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3 - c)) return false; // 3 - c 可以把1 变成2  把2变成1
        }
        else if(color[j] == c)return false;
    }
    return true;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    
    int a, b;
    
    while(m --) {
        scanf("%d%d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    
    bool flag = true;
    
    for(int i = 1; i <= n; i ++){
        if(!color[i]){
            if(!dfs(i, 1)){ // 如果没染色 将i染为第一种颜色
                flag = false;
                break;
            }
        }
    }
    
    if(flag) puts("Yes");
    else puts("No");
 
    return 0;
}

