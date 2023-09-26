#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 410, INF = 0x3f3f3f3f;

int w[N], dp1[N][N], dp2[N][N], s[N];
int n;

int main () {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) {
        cin >> w[i];
        w[i + n] = w[i];
    }
    
    for (int i = 1; i <= 2 * n; i ++) {
        s[i] = s[i - 1] + w[i];
    }
    
    memset(dp1, 0x3f, sizeof dp1);
    memset(dp2, -0x3f, sizeof dp2);
    
    for (int len = 1; len <= n; len ++) {
        for (int i = 1; i + len - 1 <= 2 * n; i ++) {
            int l = i, r = i + len - 1;
            
            if (len == 1) dp1[l][r] = dp2[l][r] = 0;
            
            else {
                for (int k = l; k < r; k ++) {
                    dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + s[r] - s[l - 1]);
                    dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + s[r] - s[l - 1]);
                }
            }
        }
    }
    
    int max_v = -INF, min_v = INF;
    
    for (int i = 1; i < n; i ++) {
        max_v = max(max_v, dp2[i][i + n - 1]);
        min_v = min(min_v, dp1[i][i + n - 1]);
    }
    
    printf("%d\n%d\n", min_v, max_v);
    
    return 0;
}
