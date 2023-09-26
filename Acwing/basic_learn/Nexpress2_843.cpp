#include <iostream>

using namespace std;

const int N = 20;

bool row[N], col[N], dg[N], udg[N];

char g[N][N];


int n;

void dfs(int x, int y, int s){ // 按照格子枚举并且为从左到右依次枚举  即按照行枚举  
    if(y == n){ // dfs本质是递归 需要给出边界条件（防止越界）  和 递归终止条件（得到答案)
        y = 0;
        x ++;  
    }
    
    if(x == n){ // 需要判断x的位置  是结束条件之一
        if(s == n){ // 第二个结束条件
            for(int i = 0; i < n; i ++) puts(g[i]);
            puts("");
        }
        return; // 注意return 的位置
    }
    
    
    // 不放皇后
    dfs(x, y + 1, s);
    
    // 放皇后
    
    // for(int i = 0; i < n; i++){//  不需要列举i了 因为这种写法就是一个一个列举  x y 已经代表了行号和列号
        if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]){
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            g[x][y] = 'Q';
            dfs(x, y + 1, s + 1);
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
            g[x][y] = '.';
        }
    
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';
            
    dfs(0, 0, 0);
    return 0;
}





// 对于本题  稍加修改 可以得到  只找出一种方案就停止搜索的代码  如下
#include <iostream>

using namespace std;

const int N = 20;

bool row[N], col[N], dg[N], udg[N];

char g[N][N];


int n;

bool dfs(int x, int y, int s){ // 按照格子枚举并且为从左到右依次枚举  即按照行枚举  
    if(y == n){ // dfs本质是递归 需要给出边界条件（防止越界）  和 递归终止条件（得到答案)
        y = 0;
        x ++;  
    }
    
    if(x == n){ // 需要判断x的位置  是结束条件之一
        if(s == n){ // 第二个结束条件
            for(int i = 0; i < n; i ++) puts(g[i]);
            puts("");
            return true; 
        }
        return false; // 注意return 的位置 return 的作用是终止这一层  放回到上一层
    }
    
    
    // 不放皇后
    if(dfs(x, y + 1, s)) return true;
    
    // 放皇后
    
    // for(int i = 0; i < n; i++){//  不需要列举i了 因为这种写法就是一个一个列举  x y 已经代表了行号和列号
        if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]){
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            g[x][y] = 'Q';
            if(dfs(x, y + 1, s + 1)) return true;
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
            g[x][y] = '.';
        }
    return false;
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';
            
    dfs(0, 0, 0);
    return 0;
}
