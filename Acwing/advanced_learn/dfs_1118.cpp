#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 11;

int group[N][N];
int nums[N];
bool st[N];
int n;
int ans = N;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool check(int group[], int x, int start) {
    for (int i = 0; i < start; i ++) {
        if (gcd(nums[group[i]], x) > 1) return false;
    }
    return true;
}

// total_cnt 已经搜（放）了多少个数（所以最开始是0个） 所以等于n的时候输出答案
//           当前放的组    当前放的组该放的位置  nums中处理到第几个数
void dfs(int num_group, int start_group, int start_num, int total_cnt) {
    if (num_group >= ans) return;
    if (total_cnt == n) ans = num_group;
    bool flag = true; // 当前组没有放新的元素
    for (int i = start_num; i < n; i ++) {
        if (!st[i] && check(group[num_group], nums[i], start_group)) {
            st[i] = true;
            
            group[num_group][start_group] = i;
            dfs(num_group, start_group + 1, start_num + 1, total_cnt + 1);
            flag = false;
            st[i] = false;
            
            // 当前组长度为0，则开新组，可以开新组这说明当前数也只能放到新组
            // 等效于放到之后的任意新组，可以直接剪枝
            if (start_group == 0) return ;
        }
    }
    
    if (flag) dfs(num_group + 1, 0, 0, total_cnt);
}


int main() {
    cin >> n;
    
    for (int i = 0; i < n; i ++) cin >> nums[i];
    
    dfs(1, 0, 0, 0);
    cout << ans << '\n';
    return 0;
}
