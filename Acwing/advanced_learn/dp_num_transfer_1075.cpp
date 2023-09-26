#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;
int h[N], e[N], ne[N], idx;
int fac_sum[N];
bool has_fa[N];
int n;
int ans;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dfs(int u) {
    int fir = 0, sec = 0;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        int dist = dfs(j) + 1;
        if (dist >= fir) sec = fir, fir = dist;
        else if (dist > sec) sec = dist;
    }
    ans = max(ans, fir + sec);
    return fir;
}


int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 2; j <= n / i; j ++ ) {
            fac_sum[i * j] += i;
        }
    }
    
    // 按照本题的处理fac_sum[1] = 0, 这样0->1 有边  不符合正整数的题意  所以i从2开始
    // 建单向边是因为保证对应关系不混乱 https://www.acwing.com/solution/content/65467/
    // 单向边找直径需要从根节点开始  所以用一个数组记录根节点
    for (int i = 2; i <= n; i ++) {
        if (i > fac_sum[i]) {
            add(fac_sum[i], i);
            has_fa[i] = true;
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        if (!has_fa[i])
            dfs(i);
    }
    
    printf("%d\n", ans);
    
    
}
