#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second


using namespace std;
typedef pair<int, int> PII;

const int N = 3e4 + 10;


PII goods[N];
int dp[N];

int main(){
    int n, m;
    cin >> m >> n;

    for(int i = 1; i <= n; i ++){
        int v, w;
        cin >> v >> w;
        goods[i] = {v, v * w};

    }

    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= goods[i].x; j --){
            dp[j] = max(dp[j], dp[j - goods[i].x] + goods[i].y);
        }
    }

    cout << dp[m] << endl;

    return 0;

}
