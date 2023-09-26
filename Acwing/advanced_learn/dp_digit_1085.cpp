#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 10;
int f[N][10];

void init() {
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i ++) {
        if (i != 4) f[1][i] = 1;
    }
    
    for (int i = 2; i < N; i ++) {
        for (int j = 0; j <= 9; j ++) {
            if (j == 4) continue;
            for (int k = 0; k <= 9; k ++) {
                if (k == 4 || (j == 6 && k == 2)) continue;
                f[i][j] += f[i - 1][k]; 
            }
        }
    }
}

int help(int n) {
   if (!n) return 1;
   
   vector<int> nums;
   while (n) nums.push_back(n % 10), n /= 10;
   
   int res = 0, last = 0;
   for (int i = nums.size() - 1; i >= 0; i --) {
       int cur = nums[i];
       
       for (int j = 0; j < cur; j ++) {
           if (j == 4 || (last == 6 && j == 2)) continue;
           res += f[i + 1][j];
       }
       if (cur == 4 || (last == 6 && cur == 2)) break;
       else last = cur;
       
       if (!i) res ++;
   }
   return res;
}

int main() {
    
    int l, r;
    
    while (cin >> l >> r, l || r){
        init();
        cout << help(r) - help(l - 1) << '\n';
    }
    
    return 0;
}
