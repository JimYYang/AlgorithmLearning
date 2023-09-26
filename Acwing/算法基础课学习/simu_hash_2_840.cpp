// 开放寻址法
// 开放的数组为题目的两到三倍
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int  N = 200003, no = 0x3f3f3f3f;

int h[N];

int find(int x)// 如果存在 返回存储的位置  如果不存在  返回应该存储的位置
{
    int k = (x % N  + N) % N;
    
    while(h[k] != no && h[k] != x)
    {
        k ++;
        if(k == N)k = 0;
    }
    return k;
}

int main()
{
    memset(h, 0x3f, sizeof(h)); // memset是按照位来赋值的  int为4个字节 0x为16进制  3f八位 一个字节  将四个字节赋值为3f  一般初始化为最大整数也是这个数
    int n;
    scanf("%d", &n);
    char op[2];
    int x;
    
    while(n --)
    {
        scanf("%s%d", op, &x);
        if(op[0] == 'Q')
        {
            if(h[find(x)] == x)puts("Yes");
            else
            {
                puts("No");
            }
        }
        else
        {
            h[find(x)] = x;
        }
    }
   return 0; 
}
