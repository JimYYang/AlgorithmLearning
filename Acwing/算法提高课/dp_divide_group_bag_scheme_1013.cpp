#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 11, M = 16;
int w[N][M];
int dp[N][M];
int way[N];
int n, m;

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &w[i][j]);
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            for(int k = 0; k <= j; k ++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
            }
        }
    }

    cout << dp[n][m] << endl;

    int j = m;

    for(int i = n; i >= 1; i --){
        for(int k = 0; k <= j; k ++){
            if(dp[i][j] == dp[i - 1][j - k] + w[i][k]){
                way[i] = k;
                j -= k;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i ++) printf("%d %d\n", i, way[i]);

    return 0;
}
