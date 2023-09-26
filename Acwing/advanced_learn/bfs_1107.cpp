#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    string res(8, '0');
    for (int i = 0; i < 8;i ++) cin >> res[i];
    unordered_map<string, int> mp;
    queue<pair<string, string>> que;
    
    que.push({"12345678", ""});
    
    while (!que.empty()) {
        auto tmp = que.front();
        que.pop();
        string cur = tmp.first;
        string operation = tmp.second;
        if (cur == res) {
            if (operation == "") cout << "0\n";
            else cout << operation.size() << '\n' << operation;
            break;
        }
        
        string A, B, C;
        A = {cur[7], cur[6], cur[5], cur[4], cur[3], cur[2], cur[1], cur[0]};
        B = {cur[3], cur[0], cur[1], cur[2], cur[5], cur[6], cur[7], cur[4]};
        C = {cur[0], cur[6], cur[1], cur[3], cur[4], cur[2], cur[5], cur[7]};
        if (!mp[A]) mp[A] ++ , que.push({A, operation + "A"});
        if (!mp[B]) mp[B] ++ , que.push({B, operation + "B"});
        if (!mp[C]) mp[C] ++ , que.push({C, operation + "C"});
    }
    return 0;
    
}
