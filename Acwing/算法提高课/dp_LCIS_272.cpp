#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3010;
int a[N], b[N];
int dp[N][N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )cin >> a[i];
    for (int i = 1; i <= n; i ++ )cin >> b[i];
    
    for(int i = 1; i <= n; i ++){
        int maxl = 1;
        for(int j = 1; j <= n; j ++){
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], maxl);
            if(b[j] < a[i]) maxl = max(dp[i- 1][j] + 1, maxl);
        }
    }
    
    int res = 0;
    
    for(int i = 1; i <= n; i ++)res = max(res, dp[n][i]);
    
    cout << res;
    return 0;
}
