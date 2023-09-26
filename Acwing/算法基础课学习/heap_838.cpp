#include <iostream>
#include <algorithm>


using namespace std;


// 按照完全二叉树建堆

const int N = 100010;
int h[N], sz;

int n, m;

void down(int u)// 注意u是编号
{
    int t = u;
    if(2 * u <= sz && h[2 * u] < h[t] )t = 2 * u;
    if(2 * u + 1 <= sz && h[2 * u + 1] < h[t] )t = 2 * u + 1;
    if(t != u){
        swap(h[t], h[u]);
        down(t);
    }
    
}
int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; ++i)scanf("%d", &h[i]);
    sz = n;
    
    for(int i = n / 2; i >= 1; --i)down(i); // 建堆操作就是down(i)  从n / 2开始是因为可以将时间复杂度变为 O(n)
    while(m--){
        printf("%d ", h[1]);
        h[1] = h[sz];
        sz --;
        down(1);
    }
    return 0;
}
