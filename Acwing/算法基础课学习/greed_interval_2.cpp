// 这题和上一题一样  最大不相交的区间  需要至少cnt个点才能完全覆盖

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
struct Range{
  int l, r;
  bool operator< (const Range &a)const
  {
      return r < a.r;
  }
}range[N];


int main(){
    int n;
    scanf("%d", &n);
    
    int a, b;
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0, end =-2e9;
    
    for(int i = 0; i < n; i ++){
        if(end < range[i].l){
            res ++;
            end = range[i].r;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
