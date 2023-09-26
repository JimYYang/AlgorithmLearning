#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int dp[N], a[N];
int n;

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i ++)cin >> a[i];
    
    for(int i = 1; i <= n;i ++){
        dp[i] = a[i];
        
        for(int j = 1; j < i; j ++){
            if(a[i] > a[j]){
                    dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    
    // 记录每个以i结尾的上升子序列错误的原因是 对于4 2 5 不知道选择 的是2 5 还是4 5
    // int res = -1;
    // for(int i = 1; i <= n; i ++){
    //     int sum = 0;
    //     int k = i;
    //     for(int j = 0; j < dp[i]; j ++){
    //         sum += a[k];
    //         cout << a[k] << " ";
    //         k = pre[k];
    //     }
    //     cout <<endl;
        
    //     res = max(res, sum);
    // }
    
    int res = -1;
    for (int i = 1; i <= n; i ++ )res = max(res, dp[i]);
    cout << res << '\n';
    
    return 0;
}
