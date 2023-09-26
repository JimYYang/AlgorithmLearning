#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_prime(int n){
    if(n < 2)return false;
    for(int i = 2; i <= n / i; i ++){
        if(n % i == 0)return false;
    }
    return true;
}

int main(){
    int n;
    
    scanf("%d", &n);
    while( n-- ){
        int x;
        scanf("%d", &x);
        if(is_prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}
