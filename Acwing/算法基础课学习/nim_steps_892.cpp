#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int n;
/*
可以这样理解： 偶数台阶需要拿偶数次才能到地面，就相当于是把偶数个相同数量的石子堆拿完的策略。
正好可以转化成前面一道题的“偶数个石子堆异或在一起，并且这些石子数量相同”，结果必然是0，因此可以不考虑。

*/

int main(){
    scanf("%d", &n);
    
    int res = 0, x;
    for(int i = 1; i <= n;i ++){
        scanf("%d", &x);
        if(i & 1)res ^= x;
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
}
