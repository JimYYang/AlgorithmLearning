#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

int a[N];
struct Node {
    int l, r;
    LL sum, add;
}tr[N << 2];
int n, m;

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add;
        right.add += root.add;
        left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, a[l], 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        // if (r <= mid) modify(u << 1, l, r, v);
        // else modify(u << 1 | 1, l, r, v);
        // pushup(u);
        
        // 区间修改 所以和单点不一样  这里是区别
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    else if (l > mid) return query(u << 1 | 1, l, r);
    else return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    // LL res = 0;
    // if (l <= mid) res = query(u << 1, l, r);
    // if (r > mid) res += query(u << 1 | 1, l, r);
    // return res;
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    build(1, 1, n);
    
    char op[2];
    int l, r, d;
    
    while (m --) {
        scanf("%s%d%d", op, &l, &r);
        
        if (*op == 'Q') {
            printf("%lld\n", query(1, l, r));
        }
        else {
            scanf("%d", &d);
            modify(1, l, r, d);
        }
    }
    return 0;
}
