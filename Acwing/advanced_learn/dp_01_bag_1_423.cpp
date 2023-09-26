#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
int dp[N];
int v[N], w[N];
int main(){
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= m; i ++)
        scanf("%d%d", &v[i], &w[i]);
        
    for(int i = 1; i <= m; i ++){
        for(int j = n; j >= v[i]; j --){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}
