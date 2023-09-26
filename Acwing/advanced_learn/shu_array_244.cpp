#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], tr[N], ans[N];
int n;

int lowbit(int x)  // 返回末尾的1
{
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++) tr[i] = lowbit(i);
    
    for (int i = n; i; i --) {
        int h = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum(mid) >= h) r = mid;
            else l = mid + 1;
        }
        ans[i] = r;
        add(r, -1);
    }
    
    for (int i = 1; i <= n; i ++ ) printf("%d\n", ans[i]);
    return 0;
}
