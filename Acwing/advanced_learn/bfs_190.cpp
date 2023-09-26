#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 6;
string a[N], b[N];
int n;

int extend(queue<string> & que, unordered_map<string, int> &mp_a, unordered_map<string, int> & mp_b,
string a[], string b[]) {
    int dist = mp_a[que.front()];
    
    while (que.size() && mp_a[que.front()] == dist) {
        auto cur = que.front();
        que.pop();
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < cur.size(); j ++) {
                if (cur.substr(j, a[i].size()) == a[i]) {
                    string new_state = cur.substr(0, j) + b[i] + cur.substr(j + a[i].size());
                    if (mp_a.count(new_state)) continue; // 这个和下一行谁的位置靠前无所谓
                    // 因为在bfs中 我们只关心第一次被搜到（入队）
                    if (mp_b.count(new_state)) return mp_a[cur] + mp_b[new_state] + 1;
                    mp_a[new_state] = mp_a[cur] + 1;
                    que.push(new_state);
                }
            } 
        }
    }
    return 11;
}

int bfs(string A, string B) {
    if (A == B) return 0;
    queue<string> que_a, que_b;
    unordered_map<string, int> mp_a, mp_b;
    que_a.push(A), que_b.push(B);
    mp_a[A] = 0, mp_b[B] = 0;
    
    int step = 0;
    while (que_a.size() && que_b.size()) {
        int t;
        if (que_a.size() <= que_b.size()) t = extend(que_a, mp_a, mp_b, a, b);
        else t = extend(que_b, mp_b, mp_a, b, a);
        if (t <= 10) return t;
        if (++ step == 10) return -1;
    }
    return -1;
}

int main() {
    string A, B;
    
    cin >> A >> B;

    while (cin >> a[n] >> b[n]) n ++;
    
    int res = bfs(A, B);
    
    if (res == -1) puts("NO ANSWER!");
    else cout << res << '\n';
    return 0;
}
