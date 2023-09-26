// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<string>

// using namespace std;

// const int N = 1010;

// int v[N], w[N];
// int dp[N][N];

// int main(){
//   int n, m;
   
//   scanf("%d%d", &n, &m);
   
//   for(int i = 1; i <= n; i ++)scanf("%d%d", &v[i], &w[i]);
   
//   for(int i = 1; i <= n; i ++){
//       for(int j = 0; j <= m; j ++){
//           for(int k = 0; k * v[i] <= j; k ++){
//               dp[i][j] = max(dp[i][j], dp[i-1][j - k * v[i]] + k * w[i]);
//           }
//       }
//   }
   
//   printf("%d\n", dp[n][m]);
   
//   return 0;
// }






// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<string>

// using namespace std;

// const int N = 1010;

// int v[N], w[N];
// int dp[N][N];

// int main(){
//   int n, m;
   
//   scanf("%d%d", &n, &m);
   
//   for(int i = 1; i <= n; i ++)scanf("%d%d", &v[i], &w[i]);
   
//   for(int i = 1; i <= n; i ++){
//       for(int j = 0; j <= m; j ++){
//             //dp[i][j] = max(dp[i][j], dp[i-1][j - k * v[i]] + k * w[i]);
//             dp[i][j] = dp[i-1][j]; // 不选
//             if(j >= v[i])dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//       }
//   }
   
//   printf("%d\n", dp[n][m]);
   
//   return 0;
// }




#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

const int N = 1010;

int v[N], w[N];
int dp[N];

int main(){
   int n, m;
   
   scanf("%d%d", &n, &m);
   
   for(int i = 1; i <= n; i ++)scanf("%d%d", &v[i], &w[i]);
   
   for(int i = 1; i <= n; i ++){
       for(int j = v[i]; j <= m; j ++){
            //dp[i][j] = max(dp[i][j], dp[i-1][j - k * v[i]] + k * w[i]);
            //dp[i][j] = dp[i-1][j]; // 不选
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]); // 改成一维不能逆序j  因为用到的是本轮的 dp[j-v[i]]
       }
   }
   
   printf("%d\n", dp[m]);
   
   return 0;
}
