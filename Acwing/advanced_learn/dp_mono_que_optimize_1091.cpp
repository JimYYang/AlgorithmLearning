#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int row_max[N][N], row_min[N][N];
int matrix[N][N];
int temp[N], col_max[N], col_min[N];
int que[N];
int n, m, k;

void get_max(int nums[], int ans[], int n) {
    int hh = 0, tt = -1;
    
    for (int i = 1; i <= n; i ++) {
        if (hh <= tt && que[hh] < i - k + 1) hh ++;
        while (hh <= tt && nums[que[tt]] <= nums[i]) tt --;
        que[++ tt] = i;
        if (i >= k) ans[i] = nums[que[hh]];
    }
}

void get_min(int nums[], int ans[], int n) {
    int hh = 0, tt = -1;
    
    for (int i = 1; i <= n; i ++) {
        if (hh <= tt && que[hh] < i - k + 1) hh ++;
        while (hh <= tt && nums[que[tt]] >= nums[i]) tt --;
        que[++ tt] = i;
        if (i >= k) ans[i] = nums[que[hh]];
    }
}


int main() {
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++ ){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        get_max(matrix[i], row_max[i], m);
        get_min(matrix[i], row_min[i], m);
    }
    
    int res = 2e9;
    for (int i = k; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            temp[j] = row_max[j][i];
        }
        get_max(temp, col_max, n);
        
        for (int j = 1; j <= n; j ++) {
            temp[j] = row_min[j][i];
        }
        get_min(temp, col_min, n);
        
        for (int j = k; j <= n; j ++)
            res = min(res, col_max[j] - col_min[j]);
    }
    
    printf("%d\n", res);
    return 0;
}
