#include<iostream>

using namespace std;
//角标对应问题 初始化问题 为0 
//差分和前缀和  都要主要是自己处理输入输出还是不用处理
//若不用处理  则角标需要主要   若自己处理 角标都从1开始 且初始化为0
const int N = 100010;
int n,k;
int q[N], diff[N];
void insert(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++){
        scanf("%d", &q[i]);
        insert(i + 1, i + 1, q[i]);
    }
    while(k--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r,c);
    }
    for(int i = 1; i <= n; ++i)diff[i] += diff[i-1];
    for(int i = 1; i <= n; ++i)printf("%d ", diff[i]);
    return 0;
    
    
}
