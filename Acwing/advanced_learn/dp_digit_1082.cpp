#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 15;
int f[N][10];


void init() {
    memset(f, 0, sizeof f);
    
    for (int i = 0; i <= 9; i ++) f[1][i] = 1;
    
    for (int i = 2; i < N; i ++) {
        for (int j = 0; j <= 9; j ++) {
            for (int k = j; k <= 9; k ++) {
                f[i][j] += f[i - 1][k];
            }
        }
    }
}

int help(int n) {
    if(!n) return 1;
    
    vector<int> nums;
    
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0, last = 0;
    
    for (int i = nums.size() - 1; i >= 0; i --) {
        int cur = nums[i];
        
        for (int j = last; j < cur; j ++) {
            res += f[i + 1][j];
        }
        if (cur < last) break;
        else {
            last = cur;
        }
        if (!i && cur >= last) res ++;
    }
    return res;
}



int main() {
    init();
    int l, r;
    while (scanf("%d%d", &l, & r) == 2) {
        printf("%d\n", help(r) - help( l - 1));
    }
    
    return 0;
}
