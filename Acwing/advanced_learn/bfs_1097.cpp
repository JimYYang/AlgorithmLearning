#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M = N * N;

char grid[N][N];
PII que[M];
bool st[N][N];
int n, m;

void bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    st[sx][sy] = true;
    que[0] = {sx, sy};
    
    while (hh <= tt) {
        PII cur = que[hh ++];
        for (int i = cur.x - 1; i <= cur.x + 1; i ++) {
            for (int j = cur.y - 1; j <= cur.y + 1; j ++) {
                if (i == sx && j == sy) continue;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (grid[i][j] == '.' || st[i][j]) continue;
                que[++ tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i ++) scanf("%s", grid[i]);
    
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}

