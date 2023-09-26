#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;

const int N = 18, M = 1 << 18;
const double eps = 1e-8;

int n, m;
PDD q[N];
int f[M];
int path[N][N];

int cmp(double x, double y)
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

int main () {
    int T;
    cin >> T;
    while (T --) {
        
        cin >> n >> m;
        for (int i = 0; i < n; i ++ ) cin >> q[i].x >> q[i].y;
        
        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i ++) {
           path[i][i] = 1 << i; // 可能存在一条抛物线只覆盖一个点的情况
           
            for (int j = 0; j < n; j ++) {
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if (!cmp(x1, x2)) continue;
                
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                double b = y1 / x1 - a * x1;

                if (cmp(a, 0) >= 0) continue;
                int state = 0;
                for (int k = 0; k < n; k ++) {
                    double x = q[k].x, y = q[k].y;
                    if (!cmp(a * x * x + b * x, y)) state += 1 << k;
                }
                path[i][j] = state; // 能够覆盖点i和点j的抛物线  并且这条抛物线还可能覆盖其他的点

           }
        }
        
        memset(f, 0x3f, sizeof f); // 因为本题的更新状态时不确定的 所以为了保证合法的转移 需要初始化
        
        f[0] = 0; //有多组测试数据
        
        // 枚举到(1 << n) - 2是因为每次枚举会更新到至少多一个1的状态  所以全1的状态在这次会被更新
        for (int i = 0; i + 1 < 1 << n; i ++) {
            int x = 0;
            for (int j = 0; j < n; j ++) {
                if (!(i >> j & 1)) {
                    // 只需要任选一个是因为一次只会消灭这一头小猪 枚举完了能覆盖该小猪的所有抛物线
                    x = j;
                    break;
                }
            }
            for (int j = 0; j < n; j ++){ // dp 核心 用某个状态去更新其他状态
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
            }
        }
        
        cout << f[(1 << n) - 1] << endl;
    }
    
    return 0;
}

