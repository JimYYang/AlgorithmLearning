// 遍历所有方案需要回溯  不同的棋盘状态搜 需要回溯
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10;
bool st[N][N];
int n, m, x, y;
int ans;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt) {
    if (cnt == n * m) {
        ans ++;
        return ;
    }
    
    st[x][y] = true;
    
    for (int i = 0; i < 8; i ++) {
        int a = x + dx[i], b = y + dy[i];
        
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b]) continue;
        dfs(a, b, cnt + 1);
    }
    st[x][y] = false;
}

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        // 这题不需要memset st数组  因为dfs时恢复了现场
        ans = 0;
        cin >> n >> m >> x >> y;
        
        dfs(x, y, 1);
        
        printf("%d\n", ans);
    }
    return 0;
}
