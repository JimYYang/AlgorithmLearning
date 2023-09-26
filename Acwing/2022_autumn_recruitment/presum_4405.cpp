#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 510;

int a[N][N], s[N][N];

int n, m, k;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
        }
    }
    
    
    LL res = 0;
    
    for(int i = 1; i <= m; i ++){
        for(int j = i; j <= m; j ++){
            for(int t = 1, f = 1; f <= n; f ++){
                while(t <= f && s[f][j] - s[t - 1][j] - s[f][i - 1] + s[t - 1][i - 1] > k)t ++;
                if(t <= f)res += f - t + 1;
            }
        }
    }
    
    printf("%lld\n",res);
    
    return 0;
    
}
