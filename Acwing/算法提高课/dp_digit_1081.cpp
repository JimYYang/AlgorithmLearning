#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 35;

int fact[N][N];
int K, B;

void init() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (!j) fact[i][j] = 1;
            else fact[i][j] = fact[i - 1][j - 1] + fact[i - 1][j];
        }
    }
}

int help(int n) {
    if (!n) return 0;
    
    vector<int> nums;
    while (n) nums.push_back(n % B), n /= B;
    
    int res = 0;
    int last = 0;
    
    for (int i = nums.size() - 1; i >= 0; i --) {
        int cur = nums[i];
        
        if (cur) {
            res += fact[i][K - last];
            
            if (cur > 1) {
                if (K >= last + 1)res += fact[i][K - last - 1];
                break;
            }
            else{
                last ++;
                if (last > K) break;
            }
        }
        
        if (!i && last == K) res ++;
    }
    return res;
}

int main() {
    init();
    
    
    int l, r;
    cin >> l >> r >> K >> B;
    
    cout << help(r) - help(l - 1) << '\n';
    
    
    return 0;
}
