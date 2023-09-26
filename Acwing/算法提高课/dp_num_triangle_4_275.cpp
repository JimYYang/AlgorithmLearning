#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 55;

int w[N][N];
int dp[2 * N][N][N];

int n, m;

int main(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> w[i][j];
        }
    }
    
    for(int k = 2; k <= m + n; k ++){
        for(int i1 = 1; i1 <= n; i1 ++){
            for(int i2 = 1; i2 <= n; i2 ++){
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m){
                    int sum = w[i1][j1];
                    if(i1 != i2)sum += w[i2][j2];
                    
                    int &v = dp[k][i1][i2];
                    
                    v = max(v, dp[k - 1][i1 - 1][i2 - 1] + sum);
                    v = max(v, dp[k - 1][i1][i2 - 1] + sum);
                    v = max(v, dp[k - 1][i1 - 1][i2] + sum);
                    v = max(v, dp[k - 1][i1][i2] + sum);
                }
            }
        }
    }
    cout << dp[m + n][n][n] << '\n';
    
    return 0;
}
