// max(x1, x2,x3, ..., xn) = y
// 去掉最后一个xn  无法求出最大值  可以做加法  不能做减法

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 24000;
int v[N], w[N];
int dp[N];

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    
    int cnt = 0;
    
    int a, b, s;
    
    for(int i = 1; i <= n; i ++){
        scanf("%d%d%d", &a, &b, &s);
        int k = 1;
        while(k <= s){
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k <<= 1;
        }
        
        if(s){
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;
    
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= v[i]; j --){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
