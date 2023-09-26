nclude <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 +10, INF = 0x3f3f3f3f;

int a[N], dp[N][2];

int main(){
    int T;
    cin >> T;
    while(T --){
        int n;
        cin >> n;
        
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        
        dp[0][0] = 0, dp[0][1] = -INF;
        
        for(int i = 1; i <= n; i ++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    
    return 0;
}
