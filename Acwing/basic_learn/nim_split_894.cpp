// 新堆的最大数量小于被分的堆(不可以取等于)
// 这题的题意是消去一堆 在放入两个新的堆  但是两个新堆的个数都要严格小于被拿走的那个  但是两个新堆总数可以大于拿走的堆
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110;
int f[N];

int sg(int x){
    if(f[x] != -1)return f[x];
    
    unordered_set<int>memo; // 虽然这里面有等价的关系 但是最好还是开局部哈希表
    
    for(int i = 0; i < x; i ++){
        for(int j = 0; j <= i;j ++){
            memo.insert(sg(i) ^ sg(j));
        }
    }
    
    
    // mex
    
    for(int i = 0; ; i ++){
        if(!memo.count(i))
            return f[x] = i;
    }
}

int main(){
    int n;
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
