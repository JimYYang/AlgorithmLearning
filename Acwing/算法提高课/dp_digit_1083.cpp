#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 11;
int f[N][10];

void init() {
    // 从0开始是因为20这种数  需要从f[1][0]转移过来
    for (int i = 0; i <= 9; i ++) f[1][i] = 1; // 这里考虑一位数需要仔细考虑0
    
    for (int i = 2; i < N; i ++) {
        for (int j = 0; j <= 9; j ++) {
            for (int k = 0; k <= 9; k ++) {
                if (abs(j - k) >= 2) 
                    f[i][j] += f[i - 1][k];
            }
        }
    }
}

int help(int n) {
    if (!n) return 0; // 这里考虑0是否是符合题目要求的数字
    
    vector<int> nums;
    
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0, last = -2;
    
    for (int i = nums.size() - 1; i >= 0; i --) {
        int cur = nums[i];
        
        for (int j = (i == nums.size() - 1); j < cur; j ++) {
            if (abs(j - last) >= 2) 
                res += f[i + 1][j];
        }
        if (abs(cur - last) < 2) break;
        else last = cur;
        
        if (!i) res ++;
        
    }
    
    // 处理1到n - 1位数
    
    for (int i = 1; i < nums.size(); i ++) {
        for (int j = 1; j <= 9; j ++) {
            res += f[i][j];
        }
    }
    return res;
}


int main() {
    init();
    
    int l, r;
    cin >> l >> r;
    cout << help(r) - help(l - 1) << '\n';
    return 0;
}
