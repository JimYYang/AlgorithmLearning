// 解法1  类似N排列的思路  遍历  定义几个数组


#include <iostream>

using namespace std;

const int N = 20;

char g[N][N];
int col[N], dg[N], udg[N];

int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return ;
    }
    for(int i = 0; i < n; i ++){
        if(!col[i] && !dg[u + i] && !udg[n - u + i]){
            g[u][i] = 'Q'; // 尝试每一列
            col[i] = dg[u + i] = udg[n - u + i] = true; // 使用截距的方法来写坐标   b = y + x  b = y - x + n
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u + i] = udg[n - u + i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0);
    
    return 0;
}
