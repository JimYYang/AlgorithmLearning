#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 1 << 24;

int n, m, k;
int w[50], weights[N];
int cnt;
int ans;

void dfs1(int u, int s) {
    if (u == k) {
        weights[cnt ++] = s;
        return;
    }
    
    if ((LL) s + w[u] <= m) dfs1(u + 1, s + w[u]);
    dfs1(u + 1, s);
}

void dfs2(int u, int s) {
    if (u == n) {
        int l = 0, r = cnt - 1;
        
        while (l < r) {
            int mid = l + r + 1 >> 1;
            
            if (weights[mid] + (LL)s <= m) l = mid;
            else r = mid - 1;
        }
        if ((LL)s + weights[l] <= m) ans = max(ans, weights[l] + s);
    
        return;
    }
    
    if ((LL)s + w[u] <= m) dfs2(u + 1, s + w[u]);
    dfs2(u + 1, s);
}


int main() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i ++) cin >> w[i];
    
    sort(w, w + n);
    reverse(w, w + n);
    
    k = n / 2;
    
    dfs1(0, 0);
    
    
    sort(weights, weights + cnt);
    int t = 1;
    
    for (int i = 1; i < cnt; i ++) {
        if (weights[i] != weights[i - 1]) {
            weights[t ++] = weights[i];
        }
    }
    
    cnt = t;
    dfs2(k, 0);
    
    cout << ans << '\n';
    return 0;
}
