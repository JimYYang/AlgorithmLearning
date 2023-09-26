#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

typedef long long LL;

const int N = 110, M = 10010;

int op[N], f[M]; // f[M]表示局面
// 这个应该每次求一个有向图的sg值的调用sg函数的时候都应该将 f 初始为 -1的吧
// 但是y总只在最开始初始化了一次f，为啥还能Ac
// f对应一种局面。如果在之前有经历过这样一种局面，那么这个局面是已经被固定了的，(只要在某个时刻石子数一样 状态唯一确定)
// 因为拿石子数的集合没变，所以那个图（局面）不会改变，所以不需要每次都初始化f（表达能力差啊哈哈）
int k, n;

// unordered_set<int>memo; // 不能定义在外面  因为每个不同的图都需要一个哈希表来存储状态
int sg(int x){
    if(f[x] != -1)return f[x];
    
    unordered_set<int>memo;
    
    for(int i = 0; i < k; i ++){
        int cur = op[i];
        if(x >= cur)memo.insert(sg(x - cur));
    }
    
    for(int i = 0; ; i ++){
        if(!memo.count(i))
            return f[x] = i; // 注意这里需要自己跳出循环 因为for里面没有终止条件
    }
}

int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i ++) scanf("%d", &op[i]);
    
    scanf("%d", &n);
    
    memset(f, -1, sizeof f);
    
    int x;
    int res = 0;
    while(n --){
        scanf("%d", &x);
        res ^= sg(x);
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
}
