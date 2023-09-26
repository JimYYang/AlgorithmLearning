// 字符串前缀哈希

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

char str[N];
ULL h[N], p[N]; // 定义为ULL是因为unsigned 溢出时相当于对 2 ^ 64取模

ULL get(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, str + 1); // 注意strc从1开始
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i]; // h[0] = 0  str[i]不为0 即可
    }
    
    int l1, r1, l2, r2;
    
    while(m --)
    {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(get(l1, r1) == get(l2, r2))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
