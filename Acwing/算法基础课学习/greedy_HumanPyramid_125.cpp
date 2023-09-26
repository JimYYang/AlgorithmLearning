// 另一种贪心思路  公式法  数学上的不等式等
// 注意本题求得是最大值的最小值  不是求和

#include <iostream>|
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 50010;
PII cow[N];

int main(){
    int n;
    scanf("%d", &n);
    
    int w, s;
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &w, &s);
        
        cow[i] = {w + s, w}; // 第二个参数按照什么排序无所谓
    }
    
    sort(cow, cow + n);
    int res = -1e9;
    
    for(int i = 0, sum = 0; i < n; i ++){
        w = cow[i].y, s = cow[i].x - w;
        res = max(res, sum - s);
        sum += w;
    }
    
    printf("%d\n", res);
    
    return 0;
    
}
