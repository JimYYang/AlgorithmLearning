#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510;
int dp[N][M];

int main(){
    int n, m, k;
    cin >> n >> m >>k;
    int v, w;
    
    while(k --){
        cin >> v >> w;
        for(int i = n; i >= v; i --){
            for(int j = m - 1; j >= w; j --){
                dp[i][j] = max(dp[i][j], dp[i - v][j - w] + 1);
            }
        }
    }
    
    cout << dp[n][m - 1] << ' ';
    
    int s = m - 1;
    while(s > 0 && dp[n][s - 1] == dp[n][m - 1])s--;
    cout << m - s << endl; // 找到最后一定是恰好用完的  也就是说抓到x个小精灵消耗的恰好是这些小精灵的体积和
    return 0;
}
