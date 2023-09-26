// 求逆元是质数的话可以用快速幂 不然只能用扩展欧几里得算法

// 火车进站 合法括号个数都是卡特兰数

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1)res = (LL) res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    int a = 2 * n, b = n;
    
    int res = 1;
    for(int i = a; i > a - b; i --)res = (LL)res * i % MOD;
    for(int i = 1; i <= b; i ++) res = (LL)res * qmi(i, MOD - 2, MOD) % MOD;
    
    res = (LL)res * qmi(n + 1, MOD - 2, MOD) % MOD;
    
    printf("%d\n", res);
    
    return 0;
}
