// lucas定理

// 在取模的情况下做除法用逆元  
// 只有质数才可以用快速幂求逆元  非质数需要使用扩展欧几里得算法


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;


int p, n;

int qmi(int a, int k){
    int res = 1;
    
    while(k){
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int C(int a, int b){
    int res = 1;
    for(int i = 1, j = a; i <= b; i ++, j --){
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }
    return res;
}


int lucas(LL a, LL b){
    if(a < p && b < p)return C(a, b);
    
    return (LL) C(a % p, b % p) * lucas(a / p, b / p) % p;
}


int main(){
    scanf("%d", &n);
    
    LL a, b;
    
    while(n--){
        scanf("%lld%lld%d", &a, &b, &p); // 处理非int的建议使用cin  cout 
        
        printf("%d\n", lucas(a, b));
    }
    
    return 0;
}
