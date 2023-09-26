// 画图
// 0-------j-(j+1)--------(i-1)-i
// s[i] - s[i - j] 不要忘记前缀和求得是s[a] - s[b - 1]
// 1<= j <= m  所以求得是s[i-1]~s[i-m]的最小值  所以区间左端点是i-m

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 3e5 + 10;
int s[N], q[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    
    int res = -2e9;
    
    int hh = 0, tt = 0;
    q[0] = 0;
    
    for (int i = 1; i <= n; i ++) {
        while (hh <= tt && i - m > q[hh]) hh ++;
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i]) tt --;
        q[++ tt] = i;
    }
    
    printf("%d\n", res);
    
    return 0;
}
