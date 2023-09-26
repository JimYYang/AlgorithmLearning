// 枚举每一列


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 110;
const double eps = 1e-6;  // 这里很容易写成int

int n;
double a[N][N]; // 这里很容易写成int

int gauss(){
    int col, row;
    
    for(col = 0, row = 0; col < n; col ++){
        int cur = row;
        for(int i = row + 1; i < n; i ++){
            if(fabs(a[i][col]) > fabs(a[cur][col]))
                cur = i;
        }
        
        if(fabs(a[cur][col]) < eps)continue; // 这里直接continue的原因是不需要再将row++ 因为最后通过row与n的关系来判断
                                      // 有一列全为0的情况 该方法也会得到上三角 只不过主对角线可能有0存在
        
        for(int i = col; i <= n; i ++)swap(a[cur][i], a[row][i]); // 注意这里交换的时候把最后一列也要移动上去 从col开始因为前面都是0
        
        for(int i = n; i >= col; i --)a[row][i] /= a[row][col]; // 注意要从后往前处理 不然第一个值就先变了
        
        for(int i = row + 1; i < n; i ++){
            if(fabs(a[i][col]) > eps){
                for(int j = n; j >= col; j --){
                    a[i][j] -= a[row][j] * a[i][col]; // a[i][col]是倍数 固定不变 倒序来做也是防止a[i][col]这个倍数被改变 i ,j 与 row, col互换的方法来记
                }
            }
        }
        row ++;
    }
    
    if(row < n){
        for(int i = row; i < n; i ++){
            if(fabs(a[i][n]) > eps)
                return 2;
        }
        return 1; // 无穷多组解
    }
    
    for(int i = n - 1; i >= 0; i --){
        for(int j = i + 1; j < n; j ++){
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    
    return 0; //唯一解
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n + 1; j ++){
            scanf("%lf", &a[i][j]); // 这里很容易写成%d
        }
    }
    
    int ans = gauss();
    
    if(! ans){
        for(int i = 0; i < n; i ++)
            if(fabs(a[i][n]) < eps)printf("0.00\n");
            else    printf("%.2lf\n", a[i][n]); // 这里很容易写成%d
    }
    
    else if (ans == 1)puts("Infinite group solutions");
    else puts("No solution");
    
    return 0;
}
