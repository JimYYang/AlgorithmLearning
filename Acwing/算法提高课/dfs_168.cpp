// dfs都会回溯  有的需要恢复现场
// 这题的恢复现场是隐式的 每次R H都会重新赋值

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 25, INF = 0x3f3f3f3f;

int R[N], H[N], min_v[N], min_s[N];
int n, m;
int ans = INF;

void dfs(int u, int s, int v) {
    if (v + min_v[u] > n) return ;
    if (s + min_s[u] >= ans) return ;
    if (s + 2 * (n - v) / R[u + 1] >= ans) return;
    if (!u) {
        if (v == n) ans = s;
        return ;
    }
    
    for (int r = min(R[u + 1] - 1, (int) sqrt((n - v) / u)); r >= u; r --) {
        for (int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h --) {
            int t = 0;
            if (u == m) t = r * r;
            
            R[u] = r, H[u] = h;
            dfs(u - 1, s + 2 * r * h + t, v + r * r * h);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i ++) {
        min_v[i] += min_v[i - 1] + i * i * i;
        min_s[i] += min_s[i - 1] + 2 * i * i;
    }
    
    R[m + 1] = H[m + 1] = INF;
    dfs(m, 0, 0);
    
    if (ans == INF) puts("0");
    else cout << ans << '\n';
    
    return 0;
}


