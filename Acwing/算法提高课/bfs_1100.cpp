#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int dist[N], que[N];
int n, k;

int bfs() {
    que[0] = n;
    memset(dist, -1, sizeof dist);
    
    dist[n] = 0;
    
    int hh = 0, tt = 0;
    
    while (hh <= tt) {
        int cur = que[hh ++];
        
        if (cur == k) return dist[cur];
        
        if (cur + 1 < N && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            que[++ tt] = cur + 1;
        }
        if (cur * 2 < N && dist[cur * 2] == -1) {
            dist[cur * 2] = dist[cur] + 1;
            que[++ tt] = cur * 2;
        }
        if (cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            que[++ tt] = cur - 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &k);
    
    printf("%d\n", bfs());
    return 0;
}
