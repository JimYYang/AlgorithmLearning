#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

using  namespace std;
const int N = 100010;
int a[N];
LL tr1[N], tr2[N];
int n, m;

int lowbit(int x)  // 返回末尾的1
{
    return x & -x;
}

void add(LL tr[], int x, LL c) {
    for (int i = x; i <= n; i +=lowbit(i)) tr[i] += c;
}

LL sum(LL tr[], int x) {
    LL res = 0;
    for (int i = x; i ; i -= lowbit(i)) res += tr[i];
    return res;
}

LL pre_sum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}


int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++) {
        int tmp = a[i] - a[i - 1];
        add(tr1, i, tmp);
        add(tr2, i, i * (LL)tmp);
    }
    
    while ( m --) {
        char op[2];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        
        if (op[0] == 'Q') {
            printf("%lld\n", pre_sum(r) - pre_sum(l - 1));
        }
        else {
            scanf("%d", &d);
            
            add(tr1, l, d), add(tr2, l, l * (LL)d);
            
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * (-d));
        }
    }
    
    return 0;
}
