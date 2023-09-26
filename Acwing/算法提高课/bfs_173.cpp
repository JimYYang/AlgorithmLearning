// bfs距离只被更新一次  入队时确定  
// dijkstra 出队时确定最短距离

#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 1010, M = N * N;
typedef pair<int, int> PII;

PII que[M];
int dist[N][N];
int n, m;
char grid[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs() {
    // 起点是手动入队的 由于bfs的性质 所有点只被更新一次 所以入队对起点设置一个特殊值
    // 其他点设置一个特殊值即可
    memset(dist, -1, sizeof dist);
    
    int hh = 0, tt = -1;
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (grid[i][j] == '1') {
                dist[i][j] = 0;
                que[++ tt] = {i, j};
            }
        }
    }
    
    while (hh <= tt) {
        PII cur = que[hh ++];
        for (int i = 0; i < 4; i ++) {
            int a = cur.x + dx[i];
            int b = cur.y + dy[i];
            
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (dist[a][b] != -1) continue;
            dist[a][b] = dist[cur.x][cur.y] + 1;
            que[++ tt] = {a ,b};
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%s", grid[i] + 1);
    
    bfs();
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
