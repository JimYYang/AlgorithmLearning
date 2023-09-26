// 预处理阶乘以及逆元

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010, MOD = 1e9 + 7; // 注意mod是质数
int n;
int infact[N], fact[N];

int pmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1)res = (LL) res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    infact[0] = fact[0] = 1;
    for(int i = 1; i < N; i ++){
        fact[i] = (LL)fact[i - 1] * i % MOD; // 可能溢出就先取模
        infact[i] = (LL) infact[i - 1] * pmi(i, MOD - 2, MOD) % MOD;
        //如果xx 是 aa 的逆元，yy 是 bb 的逆元，那么 ax≡1,by≡1ax≡1,by≡1，所以 abxy≡1abxy≡1，所以 xyxy 是 abab 的逆元
    }
    int a, b;
    
    while(n --){
        scanf("%d%d", &a, &b);
        
        printf("%d\n",(LL) fact[a] * infact[b] % MOD * infact[a - b] % MOD ); // 两个10 的九次方 乘积不会溢出 三个会
    }
}
