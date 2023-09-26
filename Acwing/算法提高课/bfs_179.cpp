#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
string op = "udlr";

int f(string s) {
    int res = 0;
    for (int i = 0; i < s.size();i ++) {
        if (s[i] != 'x') {
            int t = s[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    }
    return res;
}

string bfs(string s) {
    unordered_map<string, int> dist;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;
    heap.push({f(s), s});
    dist[s] = 0;
    
    unordered_map<string, pair<string, char>> prev;
    
    string end = "12345678x";
    
    while (heap.size()) {
        auto cur = heap.top();
        heap.pop();
        string state = cur.second;
        int step = dist[state];
        if (state == end) break;
        int x, y;
        for (int i = 0; i < state.size(); i ++) {
            if (state[i] == 'x') {
                x = i / 3;
                y = i % 3;
                break;
            }
        }
        string origin = state;
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            swap(state[x * 3 + y], state[a * 3 + b]);
            if (!dist.count(state) || dist[state] > step + 1) {
                dist[state] = step + 1;
                heap.push({dist[state] + f(state), state});
                prev[state] = {origin, op[i]};
            }
            swap(state[x * 3 + y], state[a * 3 + b]);
        }
    }
    
    string res;
    
    while (end != s) {
        res += prev[end].second;
        end = prev[end].first;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string origin, temp, seq_except_x;
    
    while (cin >> temp) {
        origin += temp;
        if (temp != "x") seq_except_x += temp;
    }
    
    int num_of_reverse = 0;
    
    for (int i = 0; i < seq_except_x.size(); i ++) {
        for (int j = i + 1; j < seq_except_x.size(); j ++) {
            if (seq_except_x[i] > seq_except_x[j]) num_of_reverse ++;
        }
    }
    
    if (num_of_reverse & 1) puts("unsolvable");
    else cout << bfs(origin) << '\n';
    return 0;
}
