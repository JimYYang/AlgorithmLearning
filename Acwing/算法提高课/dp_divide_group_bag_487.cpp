#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 65, M = 32010;

int dp[M];
PII master[N];
vector<PII> server[N];

int main(){
    int n, m;
    cin >> m >> n;

    for(int i = 1; i <= n; i ++){
        int v, w, p;
        cin >> v >> w >> p;
        if(!p)master[i] = {v, v * w};
        else server[p].push_back({v, v * w});
    }

    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= 0; j --){
            auto &sv = server[i];
            int sz = sv.size();

            for(int k = 0; k < 1 << sz; k ++){
                int v = master[i].x, w = master[i].y;
                for(int l = 0; l < sz; l ++){
                    if(k >> l & 1){
                        v += sv[l].x;
                        w += sv[l].y;
                    }
                }
                if(j >= v) dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

