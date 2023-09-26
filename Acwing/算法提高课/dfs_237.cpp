/*
离散化  题目中的数据范围很大  实际用到的范围很小
需要将大范围映射到一个小范围当中
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 10;

int p[N];

int n;
unordered_map<int, int>mp;
struct Query{
    int x, y, e;
}query[N];


int get(int x) {
    if (mp.count(x) == 0) mp[x] = ++ n;
    return mp[x];
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        int m;
        cin >> m;
        n = 0;  
        mp.clear();
        for (int i = 0; i < m; i ++) {
            int a, b, e;
            cin >> a >> b >> e;
            
            query[i] = {get(a), get(b), e};
        }
        for (int i = 1; i <= n; i ++)  p[i] = i;
        
        for (int i = 0; i < m; i ++) {
            if (query[i].e) {
               int pa = find(query[i].x), pb = find(query[i].y);
               p[pa] = pb;
            }
        }
        bool  has_conflict = false;
        for (int i = 0; i < m; i ++) {
            if (!query[i].e) {
               int pa = find(query[i].x), pb = find(query[i].y);
               if (pa == pb) {
                   has_conflict = true;
                   break;
               }
            }
        }
        
        if (has_conflict) puts("NO");
        else puts("YES");
    }
    return 0;
}
