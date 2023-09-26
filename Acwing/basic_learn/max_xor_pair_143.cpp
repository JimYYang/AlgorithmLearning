#include <iostream>

using namespace std;


// trie树用来存整数的应用

const int N = 100010, M = N * 31; // M是节点数  节点数 等于每一个元素的长度乘可能性

int son[M][2], idx;

int n, a[N];

void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(!son[p][u]){
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    // 本题不需要统计个数
}

// 该写法返回的是当前集合中与x异或值最大的数
int query(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(son[p][!u]){
            p = son[p][!u];
            res = res * 2 + !u;
        }else{
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

// 下面这种写法 直接返回当前集合中与x异或值最大的异或值

int query2(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(son[p][!u]){
            res += 1 << i; //直接加到当前结果
            p = son[p][!u];
        }else{
           //res += 0 << i; 不用写
           p = son[p][u];
        }
    }
    return res;
}

int main(){
    scanf("%d", &n);
    // for(int i = 0; i < n; ++i)scanf("%d", &a[i]); // 其实可以不用插进去  直接对每个数进行操作就行了
    int x;
    int res = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        // 边插入边操作的原因是ai aj异或具有交换性  不需要重复计算 枚举Cn 2次即可  
        // 先插入再查询 处理的是 ai 与 a0-ai的异或 因为本身异或为0  所以没有意义
        // 先查询再插入 处理的是 ai 与 a0-ai-1 的异或  两种顺序都可以
        // 先插入在查询可以避免对空集的处理
        insert(x); 
        // int t = query(x);
        res = max(res, query2(x));
    }
    printf("%d\n", res);
}

