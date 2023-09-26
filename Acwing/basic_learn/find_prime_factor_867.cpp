// 由算术基本定理可知，任何一个大于1的正整数，都可以分解成若干个质数的乘积，并且这种乘积的形式是唯一的。


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;

void divide(int n){
    for(int i = 2; i <= n / i; i ++){ // 这样看似找的是所有因数  但是其实是所有质因数  可以举例说明
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                n /= i;
                s ++;
            }
            printf("%d %d\n", i, s);
        }
    }
    
    if(n > 1)printf("%d %d\n", n, 1); // 判断是否存在大于sqrt(n)的质因数
    puts("");
}

int main(){
    scanf("%d", &n);
    
    int x;
    while(n --){
        scanf("%d", &x);
        divide(x);
    }
    
    return 0;
}
