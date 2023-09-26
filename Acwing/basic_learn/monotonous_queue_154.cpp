#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int hh, tt = -1, a[N], q[N];

// 存的是下标

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)scanf("%d", &a[i]);
    
    for(int i = 0; i < n; ++i){
        // hh <= tt是非空   i-k + 1是窗口开头位置
        // 写if 只有一次操作  写while 有多次操作  其实用的是双端队列  
        // 头部仅用于滑动窗口 尾部用于保持有序性
        while(hh <= tt && i - k + 1 > q[hh])hh++;// 说明队头已经离开窗口了  那么就应该移除队头
        while(hh <= tt && a[q[tt]] >= a[i])tt--; // 尾端出队
        
        //注意要先将元素插入到队中  因为这次操作可能是最小值
        q[++tt] = i; //存的是下标  
        
        // 输出的次数为 n-k+1 i 移动到k - 1才开始输出
        if(i >= k - 1)printf("%d ", a[q[hh]]);
    }
    puts(""); // 本行输出后换行
    
    hh = 0, tt = -1; // 自定义数据结构一定要记得初始化
     for(int i = 0; i < n; ++i){
        // hh <= tt是非空   i-k + 1是窗口开头位置
        // 写if 只有一次操作  写while 有多次操作  其实用的是双端队列  
        // 头部仅用于滑动窗口 尾部用于保持有序性
        while(hh <= tt && i - k + 1 > q[hh])hh++;// 说明队头已经离开窗口了  那么就应该移除队头
        while(hh <= tt && a[q[tt]] <= a[i])tt--; // 尾端出队
        
        //注意要先将元素插入到队中  因为这次操作可能是最大值
        q[++tt] = i; //存的是下标  
        
        // 输出的次数为 n-k+1 i 移动到k - 1才开始输出
        if(i >= k - 1)printf("%d ", a[q[hh]]);
    }
    return 0;
}
