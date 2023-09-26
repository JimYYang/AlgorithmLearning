#include <iostream>
#include <cstdio>

// 并查集可以维护很多额外的信息  需要在find和合并操作时修改  合并操作需要检查是否在同一个类中   如果不需要维护任何额外信息 不需要检查  但是最好还是检查
using namespace std;

const int N = 50010;

int p[N], d[N];
int n, k;

int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i){// 从1开始用
        p[i] = i;
    }
    int res = 0;
    while(k--){
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(x > n || y > n)res++;
        else{
        int px = find(x), py = find(y);
        if(op == 1){
           if(px == py && (d[x] - d[y]) % 3)res++; 
           else if(px != py){// 注意这里不能直接写else
               p[px] = py;
               d[px] = d[y] - d[x];
           }
        }
        else{
            if(px == py && (d[x] - d[y] - 1) % 3)res++;
            else if(px != py){
                p[px] = py;
                d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
