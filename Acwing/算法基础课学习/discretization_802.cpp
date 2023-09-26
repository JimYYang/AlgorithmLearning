#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;

int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(alls[mid] >= x)r = mid;
        else l = mid + 1;
    }
    return r + 1;//将题目给的坐标映射到1...n  从一开始是为了处理前缀和时更加方便
}

vector<int>::iterator unique(vector<int> & a){
    for(int i = 0, j = 0; i < a.size(); ++i){
        if(!i || a[i] != a[i-1]){
            a[j++] = a[i];
        }
    }
    // a[0]...a[j-1]
    return a.begin() + j;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i = 0; i < m; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(auto & cur : add){
        int x = find(cur.first);
        a[x] += cur.second;
    }
    for(int i = 1; i <= alls.size(); i++)s[i] += s[i-1] + a[i];// i <= alls.size()是因为要处理所有给出区间的数字 并且注意到
    // 因为所有的（添加和询问）坐标同时映射 所以必须写alls.size()
    for(auto & cur : query){
        int l = find(cur.first), r = find(cur.second);
        cout << s[r] - s[l - 1] <<endl;
    }
    return 0;
}
