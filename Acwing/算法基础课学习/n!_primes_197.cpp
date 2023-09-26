#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000010, M = N / 10;  // 1-n质数的个数约为 n / lnn 

int primes[M], cnt;
bool st[N];


void get_primes(int n){
    for(int i = 2; i <= n; i ++){
        if(!st[i])primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)break;
        }
    }   
}
int main(){
    int n;
    scanf("%d", &n);
    
    get_primes(n);
    
    for(int i = 0; i < cnt; i ++){
        int res = 0, tmp = n, p = primes[i];
        while(tmp){
            res += tmp / p;
            tmp /= p;
        }
        
        printf("%d %d\n", p, res);
    }
    return 0;
}
