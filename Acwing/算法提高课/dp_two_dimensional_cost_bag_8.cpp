#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int dp[N][N];

int main(){
    int n, V, M;
    scanf("%d%d%d", &n, &V, &M);
    int v, m, w;

    for(int i = 0; i < n; i ++){
        scanf("%d%d%d", &v, &m, &w);
        for(int j = V; j >= v; j --){
            for(int k = M; k >= m; k --){
                dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
            }
        }
    }
    printf("%d\n", dp[V][M]);
    return 0;
}
