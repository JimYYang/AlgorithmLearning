#include <iostream>

using namespace std;

/* 位运算常用:
 * 1. used |= 1 << i;  // 将第i位变成1
 * 2. used ^= 1 << i;  // 将第i位变成0  将第i位  1变0  0变1
 * 3. n >> i & 1;      // 求第i位
 * 4. n & -n;          // 求最右边的1
*/

const int N = 100010;
int n;

int lowbit(int x){
    return x & -x;
}
int main(){
    scanf("%d", &n);
    while(n -- ){
        int res = 0, x;
        scanf("%d", &x);
        while(x) x -= lowbit(x), res ++;
        printf("%d ", res);
    }
    return 0;
}

// int main(){
//     scanf("%d", &n);
//     while(n--){
//         int x, cnt = 0;
//         scanf("%d", &x);
//         for(int i = 31; i >= 0; i--){
//             if(x >> i & 1)cnt++;
//         }
//         printf("%d ", cnt);
//     }    
//     return 0;
// }
