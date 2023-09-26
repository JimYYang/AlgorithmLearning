#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;


const int N = 510;
char grid[N][N];
int n, m;
int dist[N][N];
bool st[N][N];

char path[] = "\\/\\/";
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
// 把格点坐标转化为方格的坐标
int trans_to_grid_x[] = {-1, -1, 0, 0}, trans_to_grid_y[] = {-1, 0, 0, -1};  

void bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0] = 0;
    
    deque<PII> que;
    que.push_back({0, 0});
    
    while (!que.empty()) {
        auto cur = que.front();
        que.pop_front();
        if (st[cur.x][cur.y]) continue;
        st[cur.x][cur.y] = true;
        
        for (int i = 0; i < 4; i ++) {
            int a = cur.x + dx[i], b = cur.y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;
            
            int grid_a = cur.x + trans_to_grid_x[i];
            int grid_b = cur.y + trans_to_grid_y[i];
            
            int d = dist[cur.x][cur.y] + (grid[grid_a][grid_b] != path[i]);
            if (d < dist[a][b]) {
                dist[a][b] = d;
                if (grid[grid_a][grid_b] != path[i]) que.push_back({a, b});
                else que.push_front({a, b});
            }
        }
    }
    
    
}

int main() {
    
    int T;
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d%d", &n, &m);
    
        for (int i = 0; i < n; i ++) {
            scanf("%s", grid[i]);
        }
    
        bfs(); 
        if (dist[n][m] == 0x3f3f3f3f) puts("NO SOLUTION");
        else printf("%d\n", dist[n][m]);
    }
    
    return 0;
    
} 
