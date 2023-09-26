//因为p是质数  所以b是p的倍数时无解

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int pmi(int a, int k, int p){
    long long res = 1;
    
    while(k){
        if( k & 1)res = res * a % p;
        k >>= 1;
        a = (long long) a * a % p;
    }
    
    return res;
}

int main(){
    scanf("%d", &n);
    
    int b, p;
    
    while(n --){
        scanf("%d%d", &b, &p);
        if(b % p == 0)puts("impossible");
        
        else printf("%d\n", pmi(b, p - 2, p));
    }
    return 0;
}
