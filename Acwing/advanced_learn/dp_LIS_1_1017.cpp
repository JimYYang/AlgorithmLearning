#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int dp[N][2];
int h[N];

int k;

int main(){
    cin >> k;
    int n;
    
    while(k --){
        cin >> n;
        for(int i = 1; i <= n; i ++)cin >> h[i];
        
        // memset(dp, 0, sizeof dp);
        // 本题也可以正向和反向各来一遍
        for(int i = 1; i <= n; i ++){
            dp[i][0] = 1;
            
            for(int j = 1; j < i; j ++){
                if(h[j] < h[i]){
                    if(dp[i][0] < dp[j][0] + 1)
                        dp[i][0] = dp[j][0] + 1;
                }
            }
        }
        
        for(int i = 1; i <= n; i ++){
            dp[i][1] = 1;
            
            for(int j = 1; j < i; j ++){
                if(h[j] > h[i]){
                    if(dp[i][1] < dp[j][1] + 1)
                        dp[i][1] = dp[j][1] + 1;
                }
            }
        }
        
        int res = -1;
        for(int i = 1; i <= n; i ++){
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
