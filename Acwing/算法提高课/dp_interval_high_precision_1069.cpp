#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;


const int N = 55;
vector<int> dp[N][N];
int w[N];
int n;

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    LL carry = 0;
    for (int i = 0; i < a.size() || carry; i ++) {
        if (i < a.size()) carry += (LL)a[i] * b;
        c.push_back(carry % 10);
        carry /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    
    return c;
}

vector<int> add (vector<int> a, vector<int> b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size() || t; i ++ ) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

bool cmp(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1;i >= 0; i --) {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

int main () {
    scanf("%d", &n);
    
    // 注意就算一位存的是123也能得到正确计算结果
    // 高精度每一位存的不是1位也能得到正确结果
    
    // vector<int> a(1, 99);
    // vector<int> b(2, 1);
    // b = add(a, b);
    // for (int i = b.size() - 1; i >= 0; i --) cout << b[i];
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    
    for (int len = 3; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++ ) {
            int r = l + len - 1;
            dp[l][r] = vector<int> (55, 1); // 初始化为无穷  也可以不初始化 在更新时判断是否为空
            for (int k = l + 1; k < r; k ++) {
                vector<int> tmp(1, 1);
                tmp = mul(tmp, w[l]);
                tmp = mul(tmp, w[k]);
                tmp = mul(tmp, w[r]);
                
                tmp = add(dp[l][k], tmp); 
                tmp = add(dp[k][r], tmp);
                if ( cmp(dp[l][r], tmp))
                    dp[l][r] = tmp;
            }
        }
    }
    
    for (int i = dp[1][n].size() - 1; i >= 0; i --)
        cout << dp[1][n][i];
    cout << '\n';
    
    return 0;
}
