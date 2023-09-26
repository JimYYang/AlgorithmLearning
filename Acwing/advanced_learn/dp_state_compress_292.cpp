#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 11;

int g[N], cnt[M], dp[2][M][M];
int n, m;
vector<int> state;

bool check(int s) {
    return !((s & (s >> 1)) ||( s & (s >> 2))); 
}

int get(int s) {
    int res = 0;
    for (int i = 0; i < m; i ++) res += s >> i & 1;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }
    }

    for (int i = 0; i < 1 << m; i ++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = get(i);
        }
    }

    for (int i = 1; i <= n + 2; i ++) {
        for (int j = 0; j < state.size(); j ++) {
            for (int k = 0; k < state.size(); k ++) {
                for (int u = 0; u < state.size(); u ++) {
                    int a = state[j], b = state[k], c = state[u];

                    if ((a & b) || (a & c) || (b & c)) continue;
                    if (g[i] & a) continue;

                    dp[i & 1][a][b] = max(dp[i & 1][a][b], dp[i - 1 & 1][b][c] + cnt[a]);
                }
            }
        }
    }
    cout << dp[n + 2 & 1][0][0] << endl;

    return 0;
}
