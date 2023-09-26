#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = 2 * N;

int h[N], w[M], e[M], ne[M], idx;
int n, ans;

void insert(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dfs(int u, int fa) {
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (int i = h[u]; ~i; i = ne[i] ) {
        int j = e[i];
        if (j == fa) continue;
        int d = dfs(j, u) + w[i];

        dist = max(dist, d);

        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }

    ans = max(ans, d1 + d2);

    return dist;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    while (-- n) {
        int a, b, c;
        cin >> a >> b >> c;
        insert(a, b, c);
        insert(b, a, c);
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}
