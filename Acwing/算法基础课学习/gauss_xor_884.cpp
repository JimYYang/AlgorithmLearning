#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 110;

int a[N][N];
int n;


int gauss(){
    int row, col;
    
    for(row = 0, col = 0; col < n; col ++){
        int cur = row;
        
        for(int i = row; i < n; i ++){
            if(a[i][col]){
                cur = i;
                break;
            }
        }
        
        if(!a[cur][col])continue;
        
        for(int i = col; i < n + 1; i ++)swap(a[cur][i], a[row][i]);
        
        for(int i = row + 1; i < n; i ++){
            if(a[i][col]){
                for(int j = col; j < n + 1; j ++){
                    a[i][j] ^= a[row][j];
                }
            }
        }
        
        row ++;
    }
    
    if(row < n){
        for(int i = row; i < n; i ++){
            if(a[i][n])
                return 2;
        }
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i --){
        for(int j = i + 1; j < n; j ++){
            a[i][n] ^= a[i][j] & a[j][n];
        }
    }
    
    return 0;
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n + 1; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    
    
    int res = gauss();
    
    if(!res){
        for(int i = 0; i < n; i ++){
            printf("%d\n", a[i][n]);
        }
    }
    
    else if(res == 1)puts("Multiple sets of solutions");
    else puts("No solution");
    
    return 0;
}
