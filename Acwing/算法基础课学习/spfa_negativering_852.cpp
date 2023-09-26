#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;

int n, m;

int idx, ne[N], e[N], w[N], h[N];

int d[N], cnt[N];

bool used[N];

void insert(int a, int b, int t){
    e[idx] = b;
    w[idx] = t;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa(){
    
    //不需要初始化d数组 
    //     可以这样理解：  虚拟节点的作用
    // 1. 构造一个虚拟节点 O，单向指向所有的节点，且到所有节点距离为0；
    // 2. 新图是否有负环等价于原始的图。
    // 3.dist数组一开始为0,没有违背算法过程，
    // 可以理解为根据算法已经从O 更新到了各个节点，接下来的代码就是顺理成章。
    // 所以dist数组从所有为0的状态开始是有对应意义的。就是先走一步。
    
    
    queue<int>q;
    for(int i = 1; i <= n; ++i){
        q.push(i);
        used[i] = true;
    }
    
    while(q.size()){
        int cur = q.front();
        q.pop();
        used[cur] = false;
        for(int i = h[cur]; i != -1; i = ne[i]){
            int j = e[i];
            
            if(d[j] > d[cur] + w[i]){
                d[j] = d[cur] + w[i];
                cnt[j] = cnt[cur] + 1;
                if(cnt[j] >= n)return true; // 注意这里  本来spfa算法不能应用于带负环的最短路径 
                // 因为会一直循环  但是这里是判断负环  会一直循环 所以这里写大于2n也对 只不过写临界值n 会更快
                if(!used[j]){
                    q.push(j);
                    used[j] = true;
                }
            }
        }
    }
    return false;
}


int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    int a, b, t; 
    while(m--){
        scanf("%d%d%d", &a, &b, &t);
        
        insert(a, b, t);
    }
    
    if(spfa())puts("Yes");
    else puts("No");
    
    return 0;
}
