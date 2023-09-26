// 要根据数据范围来进行选择

// 先预处理所有的组合数

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n;

const int N = 2010, MOD = 1e9 + 7;
int c[N][N];

void init(){
    for(int i = 0; i < N; i ++){
        for(int j = 0; j <= i; j ++){
            if(!j)c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
}


int main(){
    scanf("%d",&n);
    int a, b;
    init();
    while(n --){
        scanf("%d%d", &a, &b);
        
        printf("%d\n", c[a][b]);
    }
    
    return 0;
}
