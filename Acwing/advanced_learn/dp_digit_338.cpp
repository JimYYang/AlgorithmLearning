#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int get(vector<int> nums, int high, int low) {
    int res = 0;
    for (int i = high; i >= low; i --)
        res = nums[i] + res * 10;
    return res;
}

int power_10(int p) {
    int res = 1;
    while (p --) res *= 10;
    return res;
}

int help(int n, int digit) {
    if (!n) return 0;
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    int res = 0;
    
    int len = nums.size();
    
    for (int i = len - 1 - (digit == 0); i >= 0; i --) {
        int cur = nums[i];
        if (i < len - 1) {
            res += get(nums, len - 1, i + 1) * power_10(i);
            if (!digit) res -= power_10(i);
        }
        
        if (cur == digit) res += get(nums, i - 1, 0) + 1;
        else if (cur > digit) res += power_10(i);
    }
    return res;
}

int main() {
    int l, r;
    
    while (cin >> l >> r, l || r) {
        if (l > r) swap(l, r);
        for (int i = 0; i < 10; i ++)
            cout << help(r, i) - help(l - 1, i) << ' ';
        cout << '\n';
    }
    return 0;
}
