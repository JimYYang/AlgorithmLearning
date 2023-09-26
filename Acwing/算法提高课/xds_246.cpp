#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 5e5 + 10;

struct Node{
    int l, r;
    LL sum, res;
}tr[N << 2];

int n, m;
LL a[N];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &root, Node &l, Node &r) {
    root.sum = l.sum + r.sum;
    root.res = abs(gcd(l.res, r.res));
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        LL tmp = a[l] - a[l - 1];
        tr[u] = {l, l, tmp, tmp};
    }
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].sum += v;
        tr[u].res += v;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        }
        else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        else if (l > mid){
            return query(u << 1 | 1, l, r);
        }
        else {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    
    build(1, 1, n); // 很容易忘
    char op[2];
    int l, r;
    LL d;
    while (m --) {
        scanf("%s%d%d", op, &l, &r);
        
        if (*op == 'Q') {
            LL a_l = query(1, 1, l).sum;
            Node right = Node({0, 0, 0, 0});
            
            if (l + 1 <= r) right = query(1, l + 1, r); //  l == r需要特判
            
            printf("%lld\n", abs(gcd(a_l, right.res)));
        }
        else {
            scanf("%lld", &d);
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d); // r + 1 需要特判  否则SF  树状数组是因为判断了 i <= n
        }
    }
    return 0;
}
