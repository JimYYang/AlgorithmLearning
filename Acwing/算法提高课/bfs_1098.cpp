#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 55, M = N * N;
int grid[N][N];
PII que[M];
bool st[N][N];
int n, m;
/*

|--------> y
|
|
x
*/
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; 

int bfs(int sx, int sy) {
    que[0] = {sx, sy};
    st[sx][sy] = true;
    int hh = 0, tt = 0;
    
    while (hh <= tt) {
        auto cur = que[hh ++];
        for (int i = 0; i < 4; i ++) {
            int a = cur.x + dx[i];
            int b = cur.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b]) continue;
            if (grid[cur.x][cur.y] >> i & 1) continue;
            st[a][b] = true;
            que[++ tt] = {a, b};
        }
    }
    return hh;
}


int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int cnt = 0, area = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++){
            if (!st[i][j]) {
                area = max(area, bfs(i, j));
                cnt ++;
            }
        }
    }
    
    printf("%d\n%d\n", cnt, area);
    return 0;
}
