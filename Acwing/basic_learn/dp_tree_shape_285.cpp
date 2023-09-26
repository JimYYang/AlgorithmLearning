// 树形dp一般用递归来写  dfs  根据labu  树也是经常用递归解决
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;

int happy[N];
int dp[N][2];

int h[N], e[N], ne[N], idx;
bool has_father[N];


void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}


void dfs(int u){
    dp[u][1] = happy[u];
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        
        dfs(j); // 相当于是后根遍历 labu  dfs函数定义是以j为根的树的选和不选j的最大快乐指数和  
        
        // 以下就是后序遍历位置  复习labu
        dp[u][1] += dp[j][0];
        dp[u][0] += max(dp[j][0], dp[j][1]);
    }
    
}
int main(){
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> happy[i];
    }
    
    int a, b;
    while(-- n){ // 树有n - 1个边  节点和边两种思考方向
        cin >> a >> b;
        
        has_father[a] = true;
        insert(b, a);
    }
    
    int root = 1;
    while(has_father[root]) root ++;
    
    dfs(root);
    
    cout << max(dp[root][0], dp[root][1]) << '\n';
    
    return 0;
}
