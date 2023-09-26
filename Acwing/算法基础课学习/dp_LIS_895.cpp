// 往前看一个得到转移状态

// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 1010;

// int a[N], dp[N];


// int main(){
//     int n;
//     scanf("%d", &n);
    
//     for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
    
//     for(int i = 1; i <= n; i ++){
//         dp[i] = 1;
//         pre[i] = 0;
//         for(int j = 1; j < i; j ++){
//             if(a[j] < a[i])
//                 dp[i] = max(dp[i], dp[j] + 1);
//         }
//     }
    
//     int res = 1;
//     for(int i = 1; i <= n; i ++)res = max(res, dp[i]);
//     printf("%d\n", res);
    
//     return 0;
// }


// 记录最长子序列的版本

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int a[N], dp[N], pre[N];


int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i ++){
        dp[i] = 1;
        pre[i] = 0; // 等于0表示只有一个数
        for(int j = 1; j < i; j ++){
            if(a[j] < a[i])
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre[i] = j; //这里存的是 i 下标从哪个j下标转移过来的 
                }
        }
    }
    
    int k = 1; // 找到下标
    for(int i = 1; i <= n; i ++)
        if(dp[k] < dp[i])
            k = i;
    printf("%d\n", dp[k]);
    
    
    for(int i = 0, len = dp[k]; i < len; i ++){
        printf("%d ", a[k]);
        k = pre[k];
    }
    
    return 0;
}
