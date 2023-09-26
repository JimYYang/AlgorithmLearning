// n个数分成若干组 每组和相等  最多分多少组
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 70;
int w[N], sum, length;
bool st[N];
int n;

bool dfs(int id_bang, int len_bang, int id) {
    if (id_bang * length == sum) return true;
    if (len_bang == length) return dfs(id_bang + 1, 0, 0); // 新开棒  编号从0开始 因为有的可能没放
    
    for (int i = id; i < n; i ++ ) {
        if (st[i]) continue;
        if (len_bang + w[i] > length) continue;
        
        st[i] = true;
        
        if (dfs(id_bang, len_bang + w[i], id + 1)) return true;
        
        st[i] = false;
        
        if (!len_bang) return false;
        
        if (len_bang + w[i] == length) return false;
        
        int j = i;
        while ( j < n && w[j] == w[i]) j ++;
        i = j - 1;
    }
    return false;
}

int main() {
    while (cin >> n, n) {
        sum = 0;
        memset(st, false, sizeof st);
        for (int i = 0; i < n; i ++) {
            cin >> w[i];
            sum += w[i];
        }
        sort(w, w + n);
        reverse(w, w + n);
        length = 1;
        
        while (true) {
            if (sum % length == 0 && dfs(0, 0, 0)) {
                cout << length << '\n';
                break;
            }
            length ++;
        }
    }
    return 0;
}
