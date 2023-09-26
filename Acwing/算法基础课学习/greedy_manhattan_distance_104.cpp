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
    int res = 0;
    
    int median = a[n / 2];
    for(int i = 0; i < n; i ++)res += abs(a[i] - median);
    
    printf("%lld\n", res);
    
    return 0;
}
