#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int a[N];
int g[N], l[N];
int tr[N];
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++) {
        int y = a[i];
        g[i] = sum(n) - sum(y); // 注意sum(x) x是高度（即数的大小）
        l[i] = sum(y - 1);
        add(y, 1);
    }
    
    LL res1 = 0, res2 = 0;
    memset(tr, 0, sizeof tr);
    for (int i = n; i; i --) {
        int y = a[i];
        
        res1 += g[i] * (LL) (sum(n) - sum(y));
        res2 += l[i] * (LL) sum(y - 1);
        add(y, 1);
    }
    
    printf("%lld %lld", res1, res2);
    return 0;
}
