#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    int x;
    while(n --){
        scanf("%d", &x);
        
        int res = x;
        for(int i = 2; i <= x / i; i ++){ // 这里很容易写成 n 
            if(x % i == 0){
                res = res / i * (i - 1);
                while(x % i == 0 ) x /= i;
            }
        }
        if(x > 1)res = res / x * (x - 1);
        
        printf("%d\n", res);
    }
    return 0;
}
