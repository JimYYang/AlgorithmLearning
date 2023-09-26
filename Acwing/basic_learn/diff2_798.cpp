#include<iostream>

using namespace std;

const int N = 1010;

//要注意下标从几开始 以及转换的公式
int n, m, k;
int q[N][N], diff[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x2+1][y1] -= c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y2+1] +=c;
}


int main(){
    scanf("%d%d%d", &n, &m, &k);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &q[i][j]);
            insert(i, j, i, j, q[i][j]);
        }
    }
    while(k--){
      int x1, y1, x2, y2, c;
      scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
      insert(x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ",diff[i][j]);
        }
        puts("");//程序中puts()函数的作用与语句“printf("%s\n",s);的作用相同，可以认为puts()是printf()函数的简化版。
    }
    
    return 0;
}
