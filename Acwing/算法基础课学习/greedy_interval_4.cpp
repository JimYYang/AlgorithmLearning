// 调整法证明贪心  替换后不会变坏

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

struct Range{
  int l, r;
  bool operator < (const Range & w){
      return l < w.l;
  }
}range[N];


int main(){
    int st, ed;
    
    scanf("%d%d", &st, &ed);
    
    int n;
    scanf("%d", &n);
    
    int a, b;
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0;
    bool success = false;
    for(int i = 0; i < n; i ++){
        int j = i, max_r = -2e9;
        while(j < n && range[j].l <= st){
            max_r = max(max_r, range[j].r);
            j ++;
        }
        
        if(max_r < st){
            res = -1;
            break;
        }
        
        res ++;
        if(max_r >= ed){
            success = true; // success必须要 因为res 的值不能判断是否成功  因为可能前几个成功 大于st  但是最后的小于ed
            break;
        }
        st = max_r;
        i = j - 1; // 因为每次for循环有i++
    }
    
    if(!success)puts("-1");
    else printf("%d\n", res);
    
    return 0;
}
