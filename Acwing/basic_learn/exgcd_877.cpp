#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int n;

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    
    
    int d = gcd(b, a % b, y, x);
    y -= a /b * x;
    return d;
}

int main(){
    scanf("%d", &n);
    
    int a, b, x, y;
    
    while(n --){
        scanf("%d%d", &a, &b);
        
        gcd(a, b, x, y);
        
        printf("%d %d\n", x, y);
        
    }
    return 0;
}
