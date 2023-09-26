// 自环不需要处理  重边不需要额外处理  在算法中会自动选择最小的

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010, inf = 0x3f3f3f3f;

int idx, h[N], w[N], e[N], ne[N];

int d[N];

bool used[N];

int n, m;

void insert(int x, int y, int t){
    e[idx] = y;
    w[idx] = t; // 注意距离存储在指针之中  即idx之中
    ne[idx] = h[x];
    h[x] = idx ++;
}

int dijkstra(){
    memset(d, inf, sizeof d);
    
    d[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> q;
    
    q.push({0, 1}); // 注意  必须是先距离再节点 因为pair先按照默认的第一个参数排序
    
    while(q.size()){
        auto t = q.top();
        q.pop();
        
        int node = t.second, distance = t.first;
        
        if(used[node])continue;
        
        used[node] = true;
        
        for(int i = h[node]; i != -1; i = ne[i] ){// 遍历所有边  最多进行m次操作  所以队列里最多有m对  稀疏图遍历的是所有出边
            int j = e[i];
            
            if(d[j] > distance + w[i]){
                d[j] = distance + w[i];
                q.push({d[j], j});
            }
        }
    }
   return d[n] == 0x3f3f3f3f ? -1 : d[n]; 
}

int main(){
    memset(h , -1, sizeof h);
    
    scanf("%d%d", &n, &m);
    
    int x, y , t;
    
    while(m --){
        scanf("%d%d%d", &x, &y, &t);
        insert(x, y, t);
    }
    
    printf("%d\n", dijkstra());
    
    return 0;
}
