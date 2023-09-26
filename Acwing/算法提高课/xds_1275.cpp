#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 2e5 + 10;

struct Node{
    int l, r;
    int v;
}tr[N * 4];

int m, p;

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    return res;
}

void modify(int u, int x, int c) {
    if (tr[u].l == x && tr[u].r == x) tr[u].v = c;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, c);
        else modify(u << 1 | 1, x, c);
        pushup(u);
    }
}

int main() {
    scanf("%d%d", &m, &p);
    
    int n = 0, last = 0;
    
    build(1, 1, m);
    char op[2];
    int x;
    while (m --) {
        scanf("%s%d", op, &x);
        
        if (*op == 'Q') {
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        }
        else {
            n ++;
            modify(1, n, ((LL)last + x) % p);
        }
    }
    return 0;
}
