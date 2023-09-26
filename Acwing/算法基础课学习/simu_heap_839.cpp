#include <iostream>
// #include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], sz = 0;// 注意如果堆的规模开始就给出 那么sz = n  如果没有给出初始化为0
int n;


void heap_swap(int a, int b)
{
    // swap(hp[ph[a]], hp[ph[b]]);
    // swap(ph[a], ph[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u){
    int t = u;
    if(2 * u <= sz && h[2 * u] < h[t]) t = 2 * u;
    if(2 * u + 1<= sz && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if(t != u){
        heap_swap(t, u);
        down(t);
    }
}

void up(int u){
    while(u / 2 && h[u / 2] > h[u]){
        heap_swap(u / 2, u);
        u /= 2;
    }
}
int main(){
    scanf("%d", &n);
    cin.tie(0);
    int m = 0;
    while(n --)
    {
        string op; // 如果不用string读入的话 需要使用strcmp 需要引入cstring
        // op.resize(5);
        int k, x;
        // scanf("%s", &op[0]);
        cin >> op;
        // cout << op << endl;
        if(op == "I")
        {
            scanf("%d", &x);
            sz++; // size指向的是最后一个  而前面的链表的idx指向可用的那一个  要注意那些模型的细节
            m++;
            ph[m] = sz; // ph意义 pointer -> heap  是第m个插入的元素堆中元素存储的位置
            hp[sz] = m; // hp意义 heap -> pointer 是堆中sz位置的元素  是  第几号插入的
            h[sz] = x;
            up(sz);
        }
        else if( op == "PM")
        {
            printf("%d\n", h[1]);
        }
        else if( op == "DM")
        {
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        else if( op == "D"){
            scanf("%d", &k);
            k = ph[k]; // 注意  这里很容易写错  是通过第k个数找到堆中的下标
            heap_swap(k, sz);
            sz--;
            down(k);
            up(k);
        }
        else{
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k);
            up(k);
        }
    }
    return 0;
}
