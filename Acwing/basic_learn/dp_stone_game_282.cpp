// 注意dp数组初始化 初始化有时候直接影响问题答案
// 求最小值先初始化为max

// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 310;

// int n;
// int s[N], dp[N][N];

// int main(){
//     scanf("%d", &n);
    
//     for(int i = 1; i <= n; i ++){
//         scanf("%d", &s[i]);
//         s[i] += s[i - 1];
//     }
//     for(int len = 2; len <= n; len ++){
//         for(int i = 1; i + len - 1 <= n; i ++){
//             int l = i, r = i + len - 1;
//             dp[l][r] = 0x3f3f3f3f;
//             for(int k = l; k < r; k ++){
//                 dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
//             }
//         }
//     }
    
//     printf("%d\n", dp[1][n]);
    
//     return 0;
// }



// 注意dp数组初始化 初始化有时候直接影响问题答案
// 求最小值先初始化为max


// 打印方法
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;

int n;
int s[N], dp[N][N], way[N][N];

void print_way(int l, int r)
{
    if (l >= r) return;
    int k = way[l][r];
    print_way(l, k);
    print_way(k + 1, r);
    printf("合并 %d 到 %d 这一堆和 %d 到 %d 这一堆\n", l, k, k + 1, r);
}

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    for(int len = 2; len <= n; len ++){
        for(int i = 1; i + len - 1 <= n; i ++){
            int l = i, r = i + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            way[l][r] = 0;
            for(int k = l; k < r; k ++){
                if(dp[l][r] > dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]){
                    dp[l][r] = dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1];
                    way[l][r] = k;
                }
            }
        }
    }
    
    printf("%d\n", dp[1][n]);
    
    print_way(1, n);
    return 0;
}
