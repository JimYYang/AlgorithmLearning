// 连通性不需要恢复现场

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
char grid[N][N];
bool st[N][N];
int n, xa, ya, xb, yb;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

bool dfs(int x, int y) {
    if (grid[x][y] == '#') return false;
    if (x == xb && y == yb) return true;
    st[x][y] = true;
    
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;
        if (dfs(a, b)) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        memset(st, 0, sizeof st);
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> grid[i];
        cin >> xa >> ya >> xb >> yb;
        if (dfs(xa, ya)) puts("YES");
        else puts("NO");
    }
    return 0;
}
