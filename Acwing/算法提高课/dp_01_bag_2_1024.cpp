#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;
int dp[N];
int main(){
    int m, n; 
    cin >> m >> n;
    for(int i = 0; i < n; i ++){
        int v;
        cin >> v;
        for(int j = m; j >= v; j --)
            dp[j] = max(dp[j], dp[j - v] + v);
    }
    
    cout << m - dp[m] << endl;
    return 0;
}
