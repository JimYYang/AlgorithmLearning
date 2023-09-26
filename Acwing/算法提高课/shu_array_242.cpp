#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 100010;
LL tr[N];
int a[N];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++) add(i, a[i] - a[i - 1]);
    
    while (m --) {
        char op[2];
        int l, r, d, x;
        
        scanf("%s", op);
        if (op[0] == 'Q') {
            scanf("%d", &x);
            printf("%lld\n", sum(x));
        }
        else {
            scanf("%d%d%d", &l, &r, &d);
            add(l, d), add(r + 1, -d);
        }
    }
    return 0;
}
