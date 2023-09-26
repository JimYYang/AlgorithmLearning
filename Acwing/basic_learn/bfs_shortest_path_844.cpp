// dp 是无环的最短路问题

// 最短路的时间复杂度较高

// 二维数组的auto访问  第一层循环需要加& 即 auto & c : a 
// 二维坐标转化为一维  x * n + y   
// 方向数组int direc[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// 或者 int dx[] = {1, 0, -1, 0},  dy[] = {0, 1, 0, -1}

// dfs bfs都需要判断越界问题  

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII; // 放在using 后面

const int N = 110;

int g[N][N], d[N][N]; // d[N][N]这里起到了used数组的作用
int n, m;

// int hh , tt;
// PII q[N * N];
queue<PII> q; // 使用stl的效率和空间与自定义的栈差不多 注意全局变量的问题

int direc[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(){
    // q[0] = {0, 0}; // 注意这里是全局变量 函数内部改了等于外面改了 
    q.push({0,0});
    d[0][0] = 0;
    
    while(! q.empty()){
//     while(hh <= tt){
        // auto t = q[hh ++];
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++){
            int x = t.first + direc[i][0];
            int y = t.second + direc[i][1];
            
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                // q[++tt] = {x, y};
                q.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &g[i][j]);
    
    memset(d, -1, sizeof(d));
    
    printf("%d\n", bfs());
    return 0;
}



// 记录路径的写法


#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];
queue<PII> q ;
PII before[N][N];

int direc[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(){
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int x = t.first + direc[i][0];
            int y = t.second + direc[i][1];
            
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
                
                before[x][y] = t; // 记录这一点由哪个点过来的
            }
        }
    }
    
    int x = n - 1, y = m - 1;
    while(x || y){
        printf("%d %d\n", x, y);
        auto t = before[x][y];
        x = t.first;
        y = t.second;
    }
    return d[n - 1][m - 1];
}


int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &g[i][j]);
    
    memset(d, -1, sizeof(d));
    
    q.push({0,0});
    d[0][0] = 0;
    
    printf("%d\n", bfs());
    return 0;
}









