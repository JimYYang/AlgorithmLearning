// 只要没有负环就可以用


#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int idx, h[N], e[N], w[N], ne[N];

int d[N];
bool used[N];

int n, m;

void insert(int a, int b, int t){
    e[idx] = b;
    w[idx] = t;
    ne[idx] = h[a];
    h[a] = idx ++;
    
}

int spfa(){
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    queue<int> q;
    q.push(1);
    used[1] = true; // used记录是否在队列里
    while(q.size()){
        int cur = q.front();
        q.pop();
        
        used[cur] = false;
        
        for(int i = h[cur]; i != -1; i = ne[i]){
            int j = e[i];
            
            if(d[j] > d[cur] + w[i]){
                d[j] = d[cur] + w[i];
                if(!used[j]){
                    q.push(j);
                    used[j] = true;
                }
            }
        }
    }
    return d[n] == INF ? INF : d[n];
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    int a, b, t;
    while(m --){
        scanf("%d%d%d", &a, &b, &t);
        insert(a, b, t);
    }
    int ans = spfa();
    
    if(ans == INF) puts("impossible");
    else printf("%d\n", ans);
    
    return 0;
}




