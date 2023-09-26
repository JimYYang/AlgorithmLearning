#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second
using namespace std;

const int N = 1010, M = N * N;
typedef pair<int, int> PII;
PII que[M];
int hill[N][N];
bool st[N][N];
int n;

void bfs(int sx, int sy, bool & has_higher, bool & has_lower) {
    que[0] ={sx, sy};
    int hh = 0, tt = 0;
    st[sx][sy] = true;
    
    while (hh <= tt) {
        auto cur = que[hh ++];
        
        for (int i = cur.x - 1; i <= cur.x + 1; i ++) {
            for (int j = cur.y - 1; j <= cur.y + 1; j ++) {
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (i == sx && j == sy) continue; // 其实可以不加 因为st会过滤掉
                if (hill[i][j] != hill[sx][sy]) {
                    if (hill[i][j] > hill[sx][sy])
                        has_higher = true;
                    else has_lower = true;
                }
                else if(!st[i][j]) {
                    que[++ tt] = {i, j};
                    st[i][j] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            scanf("%d", &hill[i][j]);
        }
    }
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (st[i][j]) continue;
            bool has_higher = false, has_lower = false;
            bfs(i, j, has_higher, has_lower);
            if (!has_higher) peak ++;
            if (!has_lower) valley ++;
        }
    }
    printf("%d %d\n", peak, valley);
    return 0;
}
