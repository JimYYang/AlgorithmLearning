#include <iostream>

using namespace std;

// 先写朴素算法 再看变量之间的关系  有没有单调性

// 单调栈 本版本存的直接是数字
// 还有一种版本存的是下标
// 存下标是为了求出位置在哪 如LC_739

const int N = 100010;

int n;
int stk[N], tt;// 注意tt = 0
int a[N], res[N];

// 1. 左边  正序处理即可
// ①左边第一个小于的数  判断为>=
// ②左边第一个小于等于的数  判断为>
// ③左边第一个大于的数  判断为<=
// ④左边第一个大于等于的数  判断为<
int main(){
    scanf("%d", &n);
    // for(int i = 0; i < n; ++i)cin >> a[i];
    
    for(int i = 0; i < n; ++i){
    // for(int i = n - 1; i >= 0; i--){
        int x;
        scanf("%d", &x);
        while(tt && stk[tt] >= x)tt--; // 这个单调栈模型存的是数字  有的模型存的是下标  
                                       // 注意改为 <= 后变为左边第一个大于的数
        if(tt) printf("%d ",stk[tt]);
        else printf("-1 ");
        stk[++tt] = x; // 输出之后加入栈是因为该次数不可能为答案 
    }
    return 0;
}


// 2. 右边 数组需要逆序处理 并且答案也需要逆序存储
// ①右边第一个小于的数  判断为>=
// ②右边第一个小于等于的数  判断为>
// ③右边第一个大于的数  判断为<=
// ④右边第一个大于等于的数  判断为<

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    
    // for(int i = 0; i < n; ++i){
    for(int i = n - 1; i >= 0; i--){
        int x;
        scanf("%d", &x);
        while(tt && stk[tt] >= a[i])tt--; // 这个单调栈模型存的是数字  有的模型存的是下标  
                                       // 注意改为 <= 后变为左边第一个大于的数
        if(tt) res[i] = stk[tt];
        else res[i] = -1;
        stk[++tt] = a[i];
    }
    return 0;
}
