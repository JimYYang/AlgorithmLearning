#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long LL;
using namespace std;

const int N = 1e6 + 10, M = 2 * N;
int oil[N], dist[N], que[M];
LL sum[M];
bool ans[N];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &oil[i], &dist[i]);
    }
    
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i + n] = oil[i] - dist[i];
    
    for (int i = 1; i <= 2 * n; i ++) 
        sum[i] += sum[i - 1];
    
    int hh = 0, tt = -1;
    
    for (int i = 2 * n; i >= 1; i --) {
        if (hh <= tt && i + n <= que[hh]) hh ++;
        while (hh <= tt && sum[que[tt]] >= sum[i]) tt --;
        que[++ tt] = i;
        
        if (i <= n) {
            if (sum[que[hh]] >= sum[i - 1]) ans[i] = true;
        }
    }
    
    hh = 0, tt = -1;
    dist[0] = dist[n];
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i + n] = oil[i] - dist[i - 1];
    
    for (int i = 1; i <= 2 * n; i ++) 
        sum[i] += sum[i - 1];
        
    for (int i = 1; i <= 2 * n; i ++) {
        if (hh <= tt && i - n > que[hh]) hh ++;
        
        if (i > n) {
            if (sum[que[hh]] <= sum[i]) ans[i - n] = true;
        }
        while (hh <= tt && sum[que[tt]] <= sum[i]) tt --;
        que[++ tt] = i;
    }
    
    for (int i = 1; i <= n; i ++) {
        if (ans[i]) puts("TAK");
        else puts("NIE");
    }
    return 0;
}
