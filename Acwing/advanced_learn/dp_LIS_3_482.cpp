#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int h[N];
int dp[N][2];

int n;

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i ++)cin >> h[i];
    
    for(int i = 1; i <= n; i ++){
        dp[i][0] = 1;
        for(int j = 1; j < i; j ++){
            if(h[i] > h[j]){
                if(dp[i][0] < dp[j][0] + 1)
                    dp[i][0] = dp[j][0] + 1;
            }
        }
    }
    
    for(int i = n; i >= 1; i --){
        dp[i][1] = 1;
        for(int j = n; j > i; j --){
            if(h[i] > h[j]){
                if(dp[i][1] < dp[j][1] + 1)
                    dp[i][1] = dp[j][1] + 1;
            }
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i ++)res = max(res, dp[i][0] + dp[i][1] - 1);
    
    cout << n - res << '\n';
    
    return 0;
}
