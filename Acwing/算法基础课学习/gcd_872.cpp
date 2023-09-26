#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int n;

int main(){
    scanf("%d", &n);
    
    int a, b;
    while(n --){
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    
    return 0;
}
