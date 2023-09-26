/*
对于以上的两种搜索的顺序其实可以想象一下这样的一种情景。
即你有n个篮子你要用它们去装水果，每个篮子只能装对应种类的水果。
那么第一种方法就相当于是，你把水果任意的排成一排，
然后拿着一个篮子从第一个水果开始一个个的往后看，看看能能放到你的这个篮子中。
对于第二种方法相当于是，你把篮子放一排，
你拿着水果，然后一个个的往下看，看看能不能放在篮子里。
*/

// 互质组那题由于知道每个数之间的关系  所以可以用第一种方法  本题使用第二种方法 先搜重猫
// 减少分支数量

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int n, m;
int sum[N], w[N];
int ans = N;

void dfs(int id, int tot) {
    if (tot >= ans) return;
    if (id == n) {
        ans = tot;
        return;
    }
    
    for (int i = 0; i < tot; i ++) {
        if (sum[i] + w[id] > m) continue;
        sum[i] += w[id];
        dfs(id + 1, tot);
        sum[i] -= w[id];
    }
    
    sum[tot] = w[id];
    dfs(id + 1, tot + 1);
    sum[tot] = 0;
}

int main () {
    cin >> n >> m;
    
    
    for (int i = 0; i < n; i ++) cin >> w[i];
    
    sort(w, w + n);
    reverse(w, w + n);
    
    dfs(0, 0);
    
    cout << ans;
    return 0;
}



