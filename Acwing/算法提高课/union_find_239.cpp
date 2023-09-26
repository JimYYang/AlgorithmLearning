// mod 2意义下做加法 等价于异或运算

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 5010 * 2, BASE = N / 2;

int p[N], d[N];
int n, m;
unordered_map<int, int> mp;

int get(int a) {
    if (!mp.count(a)) mp[a] = ++ n;
    return mp[a];
}

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main() {
    for (int i = 0; i < N; i ++ ) p[i] = i;
    
    cin >> n >> m;
    
    n = 0;
    int res = m;
    for (int i = 1; i <= m; i ++) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        
        a = get(a - 1), b = get(b);
        
        int t = 0;
        
        if (type == "odd") t = 1;
        
        int pa = find(a), pb = find(b);
        
        if (pa == pb) {
            if ((d[a] ^ d[b]) != t) {
                res = i - 1;
                break;
            }
        }
        else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }
    
    cout << res << '\n';
    return 0;
}
