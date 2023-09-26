#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 25;
int n, m;
char grid[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    int cnt = 1;
    st[x][y] = true;
    
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b]) continue;
        if (grid[a][b] == '#') continue;
        cnt += dfs(a, b);
    }
    return cnt;
}

int main() {
    while (cin >> m >> n, n || m) {
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i ++) cin >> grid[i];
        int x, y;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '@') {
                    x = i,  y = j;    
                }
            }
        }
        cout << dfs(x, y) << '\n';
    }
    return 0;
}
