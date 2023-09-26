// dp转移思路 本题是往后考虑一步

// 从i ,j 开始的最大路径
// 本题用递归的写法来做比较自然 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;
int h[N][N];
int memo[N][N];

int direc[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

int dp(int x, int y){
    int &v = memo[x][y];
    if(v != -1)return v;
    
    v = 1; 
    
    for(int i = 0; i < 4; i ++){
        int a = x + direc[i][0];
        int b = y + direc[i][1];
        
        if(a >= 0 && a < n && b >= 0 && b < m && h[x][y] > h[a][b]){
            v = max(v, dp(a, b) + 1);
        }
    }
    return v;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> h[i][j];
        }
    }
    
    int res = -1;
    
    memset(memo, -1, sizeof memo);
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m;j ++){
            res = max(res, dp(i, j));
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
