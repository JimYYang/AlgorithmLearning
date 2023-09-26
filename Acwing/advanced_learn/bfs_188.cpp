#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 155, M = N * N;
char grid[N][N];
PII que[M];
int dist[N][N];
int n, m;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int sx, int sy) {
    que[0] = {sx, sy};
    memset(dist, -1, sizeof dist);
    dist[sx][sy] = 0; // 标记为已经遍历过
    
    int hh = 0, tt = 0;
    
    while (hh <= tt) {
        PII cur = que[hh ++];
        
        for (int i = 0; i < 8; i ++) {
            int a = cur.x + dx[i];
            int b = cur.y + dy[i];
            
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (dist[a][b] != -1) continue;
            if (grid[a][b] == '*') continue;
            if (grid[a][b] == 'H') return dist[cur.x][cur.y] + 1;
            dist[a][b] = dist[cur.x][cur.y] + 1;
            que[++ tt] = {a, b};
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    
    int sx, sy;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'K') {
                sx = i;
                sy = j;
            }
        }
    }
    
    printf("%d", bfs(sx, sy));
    
    return 0;
}
