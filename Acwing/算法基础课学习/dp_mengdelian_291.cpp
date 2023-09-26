#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 12, M = 1 << N;

vector<int> state[M];
LL dp[N][M];
bool valid[M];


int main(){
    int n, m;
    
    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1 << n; i ++){ // 枚举某一列的行的状态  所以写i < 1 << n
            int cnt = 0;
            bool flag = true;
            
            for(int j = 0; j < n; j ++){
                if(i >> j & 1){
                    if(cnt & 1){
                        flag = false;
                        break;
                    }
                    //不需要置零的原因是只要该二进制数前面有不合法  那整体就是不合法的  不需要检查后面的 
                }
                else cnt ++;
            }
            if(cnt & 1) flag = false; // 最后还要检查一下 
            valid[i] = flag;
        }
        
        for(int i = 0; i < 1 << n; i ++){
            state[i].clear();
            for(int j = 0; j < 1 << n; j ++){
                if((i & j) == 0 && valid[i | j]) // i | j 就是加到一起 看看第i - 1列是否偶数个0
                    state[i].push_back(j);
            }
        }
        
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        
        for(int i = 1; i <= m; i ++){
            for(int j = 0; j < 1 << n; j ++){
                for(auto k : state[j])
                    dp[i][j] += dp[i - 1][k];
            }
        }
        cout << dp[m][0] << '\n';
    }
    return 0;
}
