#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int a[N];
int dp[N], top[N], g[N];

int main(){
    while(cin >> a[n])n ++;
    int res = -1;
    // 下降序列时  既可以改条件 也可以从尾部开始扫描
    for(int i = 0; i < n; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(a[j] >= a[i]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        res = max(res, dp[i]);
    }
    
    cout << res << '\n';
    
    
    // 这题也可以用piles的方法来做
    
    // int piles = 0;
    // for (int i = 0; i < n; i ++ ){
    //     int l = 0, r = piles - 1;
        
    //     while(l <= r){
    //         int mid = l + (r - l) / 2;
    //         if(top[mid] >= a[i]) r = mid - 1;
    //         else l = mid + 1;
    //     }
    //     if(l == piles){
    //         piles ++;
    //     }
    //     top[l] = a[i];
    // }
    // cout << piles << '\n';
    
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int k = 0;
        while(k < cnt && g[k] < a[i]) k ++;
        g[k] = a[i];
        if(k >= cnt) cnt ++; // y的这种做法不需要判断是否找到  按位置直接更新即可
    }
    cout << cnt;
    
    return 0;
}
