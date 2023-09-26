#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3010;
int dp[N];

int main(){
    int n, m;
    cin >> n >> m;

    dp[0] = 1;
    int v;
    for(int i = 0; i < n; i ++){
        cin >> v;
        for(int j = v; j <= m; j ++){
            dp[j] += dp[j - v];
        }
    }
    cout << dp[m] << endl;
    return 0;
}
