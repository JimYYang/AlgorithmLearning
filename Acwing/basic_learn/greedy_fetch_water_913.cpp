// 操作系统的短作业优先算法

// 调整法 反证法 数归法 ans >= cnt  cnt <= ans法

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 100010;

int a[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)scanf("%d", &a[i]);
    
    sort(a, a + n);
    int x;
    LL res = 0;
    for(int i = 0; i < n; i ++){
        res += a[i] * (n - i - 1);
    }
    
    printf("%lld\n", res); //不是int类型就会经常在输入输出上出bug
    
    return 0;
}
