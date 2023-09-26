#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int n, a, k, p;

int qmi(int a, int k, int p){
    LL res = 1;
    
    while(k){
        if(k & 1)res = res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    
    while(n --){
        scanf("%d%d%d", &a, &k, &p);
        printf("%d\n", qmi(a, k, p));
    }
    return 0;
}
