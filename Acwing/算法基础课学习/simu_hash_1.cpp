// 对比离散化  哈希不保证有序
// 哈希函数 找一个质数

#include <iostream>
#include <cstring>

using namespace std;

// 拉链法  使用的是头插法

const int N = 100003;

int h[N], e[N], ne[N], idx; // 注意这些所有的链表共用一个数组

void insert(int x)
{
    int k = (x % N + N) % N; // 因为c++ 中  取模操作会有负数  这样是为了保证整数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx; // 注意 使用的是头插法  不是ne[k] 而是 h[k]  可以画图 h 数组上有很多链表
    idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    
    for(int i = h[k]; i != -1; i = ne[i])
    {
        if(e[i] == x)
            return true;
    }
    return false;
}

int main(){
    memset(h, -1, sizeof(h)); // 把所有链表清空  注意数据结构的初始化工作
    int n;
    scanf("%d", &n);
    char op[2];
    int x;
    
    while(n --)
    {
        scanf("%s%d", op, &x);
        if(op[0] == 'I')
        {
            insert(x);
        }
        else
        {
            if(find(x))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
