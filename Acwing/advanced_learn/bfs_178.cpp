#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;


const int N = 1010, M = 2e4 + 10;
int n, m, S, T, K;
int h[N], rh[N], idx, ne[M], e[M], w[M];
int dist[N];
bool st[N];
int cnt[N];

void insert(int h[], int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}


void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});
    
    while (heap.size() ){
        auto cur = heap.top();
        heap.pop();

        int node = cur.second;
        if (st[node]) continue;
        st[node] = true;
        
        for (int i = rh[node]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[node] + w[i]) {
                dist[j] = dist[node] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar() {
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});
    
    while (heap.size()) {
        auto cur = heap.top();
        heap.pop();
        
        int d = cur.second.first;
        int node = cur.second.second;
        cnt[node] ++;
        if (cnt[T] == K) return d;
        
        for (int i = h[node]; ~i; i = ne[i]) {
            int j = e[i];
            if (cnt[j] < K)
            // 正确的解释应该是如果当前点出队超过k次的话 
            // 用它当前权值更新的其他点必然也是大于第k次的点 所以不需要更新
                heap.push({d + w[i] + dist[j], {d + w[i], j}});
            
        }
    }
    return -1;
}


int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    
    for (int i = 0; i < m; i ++ ){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        
        insert(h, a, b, c);
        insert(rh, b, a, c);
    }
    
    scanf("%d%d%d", &S, &T, &K);
    
    if (S == T) K++;
    dijkstra();
    
    cout << astar() << '\n';
    
    return 0;
    
}
