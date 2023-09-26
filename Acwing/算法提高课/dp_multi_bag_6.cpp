#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e4 + 10;

int q[N], dp[2][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int v, w, s;
    
    for(int i = 1; i <= n; i ++){
        scanf("%d%d%d", &v, &w, &s);

        for(int r = 0; r < v; r ++){
            int hh = 0, tt = -1;

            for(int j = r; j <= m; j += v){
                while(hh <= tt && j - q[hh] > v * s) hh ++;
                while(hh <= tt && dp[(i - 1) & 1][q[tt]] + (j - q[tt]) / v * w <= dp[(i - 1) & 1][j]) tt --;
                q[++ tt] = j;
                dp[i & 1][j] = dp[(i - 1) & 1][q[hh]] + (j - q[hh]) / v * w;
            }
        }
    }
    printf("%d\n", dp[n & 1][m]);
    return 0;
}
