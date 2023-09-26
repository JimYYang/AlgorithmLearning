#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 5010;
LL dp[N];
int sum_cost[N], sum_time[N]; 

int main() {
    int n, s;
    
    cin >> n >> s;
    
    for (int i = 1; i <= n; i ++) {
        cin >> sum_time[i] >> sum_cost[i];
        sum_time[i] += sum_time[i - 1];
        sum_cost[i] += sum_cost[i - 1];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < i; j ++) {
            dp[i] = min(dp[i], dp[j] + (LL)sum_time[i] * (sum_cost[i] - sum_cost[j]) + (LL)s * (sum_cost[n] - sum_cost[j]));
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
