#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1000010;


int n;
int primes[N], cnt,  phi[N];
bool st[N];

LL get_eulers(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i ++){
        if(!st[i]){
                primes[cnt ++ ] = i;
                phi[i] = i - 1;
            }
        for(int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0){ // 说明primes[j]是i的一个质因子 不需要重复筛除了
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            else{ // % 不为0 说明primes[j] 不是i的因子  所以是primes[j] * i 的新因子
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            }
        }
    }
    LL res = 0;
    for(int i = 1; i <= n; i ++){
        res += phi[i];
    }
    return res;
}

int main(){
    scanf("%d", &n);
    
    printf("%lld", get_eulers(n));
    return 0;
}
