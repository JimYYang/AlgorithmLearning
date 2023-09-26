#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;
// 注意这些变量都被初始化为0
// 注意ne数组下标从1开始 而且ne[1] = 0 p  s下标也从1开始  
// 如果是自己处理输入输出 那么下标从1开始 自己控制 
// 如果是面试者模式  对于数组 可以使用a.insert(a.begin(), x）在头部插入一个元素来解决  字符串直接在头部加一个字符即可 使得下标变成从1开始
int n, m;
char p[N], s[M];
int ne[N];

int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    cin >> n >> p + 1 >> m >> s + 1; // 从 p s 的1下标开始存
    
    for(int i = 2, j = 0; i <= n; i++){
        while(j && p[i] != p[j+1])j = ne[j];
        if(p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= m; ++i){
        while(j && s[i] != p[j + 1])j = ne[j];
        if(s[i] == p[j + 1])j++;
        if(j == n){
            cout << i - n << ' '; //因为本题下标从0开始
            j = ne[j]; // 尝试下一次匹配
        }
    }
    return 0;
}
