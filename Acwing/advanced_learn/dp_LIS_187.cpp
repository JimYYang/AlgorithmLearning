#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55;

int n, ans;
int a[N], up[N], down[N];

void dfs(int u, int nu, int np){
    if(nu + np >= ans)return ;
    
    if(u == n){
        ans = np + nu;
        return ;
    }
    
    int k = 0;
    while(k < nu && up[k] >= a[u]) k ++; // up单调下降
    int tmp = up[k];
    up[k] = a[u];
    if(k < nu)
        dfs(u + 1, nu, np);
    else
        dfs(u + 1, nu + 1, np);
    up[k] = tmp;
    
    k = 0;
    while(k < np && down[k] <= a[u]) k ++; // up单调下降
    tmp = down[k];
    down[k] = a[u];
    if(k < np)
        dfs(u + 1, nu, np);
    else
        dfs(u + 1, nu, np + 1);
    down[k] = tmp;
    
    
}

int main(){
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        
        ans = n;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
