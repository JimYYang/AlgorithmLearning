

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

typedef long long LL;
int n;
const int mod = 1e9 + 7;

int main(){
    scanf("%d", &n);
    unordered_map<int, int> primes;
    int x;
    while(n --){
        scanf("%d", &x);
        
        for(int i = 2; i <= x / i; i ++){
            while(x % i == 0){
                
                x /= i;
                primes[i] ++;
            }
        }
        if(x > 1)primes[x] ++;
    }
    
    LL res = 1;
    
    for(auto &c : primes)res = res * (c.second + 1) % mod;
    printf("%d\n", res);
    
    return 0;
}
