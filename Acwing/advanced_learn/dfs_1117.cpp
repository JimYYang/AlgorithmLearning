#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 25;
int num_used[N];
int trans[N][N];
string words[N];
char start;
int n;
int ans;

void dfs(string dargon, int last) {
    ans = max((int)dargon.size(), ans);
    num_used[last] ++;
    
    for (int i = 0; i < n; i ++) {
        if (trans[last][i] && num_used[i] < 2)
            dfs(dargon + words[i].substr(trans[last][i]), i);
    }
    
    num_used[last] --;
    
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i ++) cin >> words[i];
    
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j < n; j ++) {
            string a = words[i], b = words[j];
            
            for (int k = 1; k < min(a.size(), b.size()); k ++) {
                if (a.substr(a.size() - k) == b.substr(0, k)) {
                    trans[i][j] = k;
                    break;
                }
            }
        }
    }
    
    cin >> start;
    
    for (int i = 0; i < n; i ++) {
        if (words[i][0] == start) {
            dfs(words[i], i);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
