#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int q[N], memo[5][N];
int n;

int f() {
    int tot = 0;
    
    for (int i = 1; i < n; i ++) {
        if (q[i - 1] + 1 != q[i]) 
            tot ++;
    }
    return (tot + 2) / 3;
}


bool dfs(int depth, int max_depth) {
    if (depth + f() > max_depth) return false;
    if (f() == 0) return true;
    
    for (int len = 1; len <= n; len ++) {
        for (int l = 0; l + len - 1 < n; l ++) {
            int r = len + l  - 1;
            for (int k = r + 1; k < n; k ++) {
                memcpy(memo[depth], q, sizeof q);
                int y = l;
                for (int x = r + 1; x <= k; x ++, y ++) q[y] = memo[depth][x];
                for (int x = l; x <= r; x ++, y ++) q[y] = memo[depth][x];
                if (dfs(depth + 1, max_depth)) return true;
                memcpy(q, memo[depth], sizeof q);
            }
        }
    }
    return false;
}


int main() {
    int T;
    cin >> T;
    
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> q[i];
        
        int depth = 0;
        while (depth < 5 && !dfs(0, depth)) depth ++;
        
        if (depth >= 5) puts("5 or more");
        else cout << depth << endl;
    }
    return 0;
}
