#include<iostream>
#include<algorithm>

using namespace std;


const int N = 1010;

int n, m, k;
int q[N][N], pre_sum[N][N];

int main(){
    scanf("%d%d%d", &n, &m,&k);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            scanf("%d", & q[i][j]);
            pre_sum[i][j] = pre_sum[i-1][j] +pre_sum[i][j-1] + q[i][j] - pre_sum[i-1][j-1];
        }
    }
    while(k--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cout << pre_sum[x2][y2] - pre_sum[x1-1][y2] - pre_sum[x2][y1-1] + pre_sum[x1-1][y1-1] <<endl;
    }
    return 0;
}
