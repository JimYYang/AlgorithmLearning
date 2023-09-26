nclude <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110, M = 25010;
int a[N], dp[M];

int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ) cin >> a[i];
        
        sort(a, a + n);
        
        memset(dp, 0, sizeof dp); // 多组测试数据记得初始化
        dp[0] = 1;
        
        int res = 0;
        
        int m = a[n - 1];
        
        for(int i = 0; i < n; i ++){
            if(!dp[a[i]]) ++res;
            
            for(int j = a[i]; j <= m; j ++){
                dp[j] += dp[j - a[i]]; // 这一层循环的意思就是使用前i个物品去拼凑
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}


