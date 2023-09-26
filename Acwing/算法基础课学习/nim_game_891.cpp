// 对比labuladong https://labuladong.github.io/algo/4/32/120/
// 所有数成对必然异或为0 反过来不对 1 ^ 2 ^ 3    每一位上成对是对的  异或运算  位运算  取模预算的常见性质


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    int res = 0;
    
    int x;
    while(n--){
        scanf("%d", &x);
        
        res ^= x;
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
}
