// bfs dfs每个节点只会遍历一次（加visited数组的情况下）
// bfs第一次遍历该点的时候才是最短路径

// 注意yxc的bfs写法和vector存邻接表写法的不同

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010; // 有向边 不需要存储两次 所以不需要定义M

int idx, h[N], ne[N], e[N]; 
int hh, tt, q[N], d[N]; // d是距离数组 也充当了visited数组
int n, m; // 注意节点编号从几开始


void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs(){
    q[++tt] = 1;
    d[1] = 0;
    while(hh <= tt){
        int cur = q[hh++];
        
        for(int i = h[cur]; i != -1; i = ne[i]){
            int j = e[i];
            
            if(d[j] == -1){
                d[j] = d[cur] + 1;
                q[++tt] = j;
            }
        }
    }    
    return d[n];
}


int main(){
    memset(d, -1, sizeof(d));
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i ++){
        scanf("%d%d", &a, &b);
        insert(a, b);
    }
    
    printf("%d\n", bfs());
    
    return 0;
}
