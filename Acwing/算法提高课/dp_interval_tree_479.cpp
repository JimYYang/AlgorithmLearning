// 方案就是记录每个决策

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35;

int dp[N][N], path[N][N], w[N];
int n;

void dfs(int l, int r) {
    if (l > r) return ;
    int root = path[l][r];
    cout << root << ' ';
    dfs(l, root - 1);
    dfs(root + 1, r);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    
    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if (len == 1) {
                dp[l][r] = w[l];
                path[l][r] = l;
            }
            
            else {
                for (int k = l; k <= r; k ++) {
                    int left = k == l ? 1 : dp[l][k - 1];
                    int right = k == r ? 1 : dp[k + 1][r];
                    int score = left * right + w[k];
                    if (score > dp[l][r]) {// 注意写大于可以保证字典序最小 等于不会更新
                        dp[l][r] = score;
                        path[l][r] = k;
                    }
                }
            }
        }
    }
    
    cout << dp[1][n] << endl;
    
    dfs(1, n);
    
    
    return 0;
}
