#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30010;

int p[N], d[N], s[N];

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < N; i ++) p[i] = i, s[i] = 1;
    while (m --) {
        char op[2];
        int a, b;
        
        scanf("%s%d%d", op, &a, &b);
        
        if (op[0] == 'M') {
            int pa = find(a), pb = find(b);
            
            if (pa != pb) {
                p[pa] = pb;
                d[pa] += s[pb];
                s[pb] += s[pa];
            }
        }
        
        else {
            int pa = find(a), pb = find(b);
            if (pa != pb) puts("-1");
            else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }
    return 0;
}
