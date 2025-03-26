#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];   // 不同长度下上升子序列结尾的最小值 
int f[N];   // 以a[i]结尾最长上升子序列长度

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int len = 0;
    for (int i = 0; i < n; i++) 
    {
        int l = 0, r = len;  // 最大长度(q的长度)
        while (l < r)   
        {
            int mid = l + r + 1 >> 1;   
            if (q[mid] < a[i]) l = mid; //找到最后一个<a[i]的位置
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
        f[i] = r + 1;
    }

    printf("%d\n", len);
    
    /*
    5
    1 2 8 6 4
    这个例子
    1 2 8 | 1 2 6 | 1 2 4
    都是最小的
    考虑本算法，对于一个长度len，假设结尾字符为a[i], i后面有更小的j, q[len]一定会被更新为a[j]
    而这里是从后往前遍历的，一定可以得到最长的，且字典序最小的
    */

    vector<int> res(len);
    for (int i = n - 1, j = len; j >= 1; i--)   //从后往前推
        if (f[i] == j)
        {
            cout << f[i] << "---" << i << endl;
            res[ -- j] = a[i];
        }

    for (auto x: res)
        cout << x << ' ';

    return 0;
}
