/* #include <iostream> */
/* #include <algorithm> */
/* #include <cstring> */

/* using namespace std; */

/* const int N = 510, M = 6010; */

/* int dp[N][M], q[M], hh, tt; */

/* int main(){ */
/*     int n, m; */
/*     scanf("%d%d", &n, &m); */

/*     int v, w, s; */

/*     for(int i = 1; i <= n; i ++){ */
/*         scanf("%d%d%d", &v, &w, &s); */

/*         for(int r = 0; r < v; r ++){ */
/*             hh = 0, tt = -1; */
/*             for(int j = r; j <= m; j += v){ */
/*                 while(hh <= tt && j - q[hh] > s * v) hh ++; */
/*                 while(hh <= tt && dp[i - 1][q[tt]] + (j - q[tt]) / v * w <= dp[i - 1][j]) tt --; */
/*                 q[++ tt] = j; */
/*                 dp[i][j] = dp[i - 1][q[hh]] + (j - q[hh]) / v * w; */ 
/*             } */
/*         } */
/*     } */
/*     printf("%d", dp[n][m]); */
/*     return 0; */
/* } */


/* #include <iostream> */
/* #include <algorithm> */
/* #include <cstring> */

/* using namespace std; */

/* const int N = 510, M = 6010; */

/* int dp[M], g[M], q[M], hh, tt; */

/* int main(){ */
/*     int n, m; */
/*     scanf("%d%d", &n, &m); */

/*     int v, w, s; */

/*     for(int i = 1; i <= n; i ++){ */
/*         scanf("%d%d%d", &v, &w, &s); */
/*         memcpy(g, dp, sizeof dp); */
/*         for(int r = 0; r < v; r ++){ */
/*             hh = 0, tt = -1; */
/*             for(int j = r; j <= m; j += v){ */
/*                 while(hh <= tt && j - q[hh] > s * v) hh ++; */
/*                 while(hh <= tt && g[q[tt]] + (j - q[tt]) / v * w <= g[j]) tt --; */
/*                 q[++ tt] = j; */
/*                 dp[j] = g[q[hh]] + (j - q[hh]) / v * w; */ 
/*             } */
/*         } */
/*     } */
/*     printf("%d", dp[m]); */
/*     return 0; */
/* } */


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 6010;

int dp[2][M], q[M], hh, tt;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int v, w, s;

    for(int i = 1; i <= n; i ++){
        scanf("%d%d%d", &v, &w, &s);

        for(int r = 0; r < v; r ++){
            hh = 0, tt = -1;
            for(int j = r; j <= m; j += v){
                while(hh <= tt && j - q[hh] > s * v) hh ++;
                while(hh <= tt && dp[i - 1 & 1][q[tt]] + (j - q[tt]) / v * w <= dp[i - 1 & 1][j]) tt --;
                q[++ tt] = j;
                dp[i & 1][j] = dp[i - 1 & 1][q[hh]] + (j - q[hh]) / v * w; 
            }
        }
    }
    printf("%d", dp[n & 1][m]);
    return 0;
}
