// 两个元素优先以哪个排序

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;

struct Range{
  int l, r;
  bool operator<(const Range &w)const{
      return l < w.l;
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
    priority_queue<int, vector<int>, greater<int>>hp;
    
    for(int i = 0; i < n; i ++){
        if(hp.empty() || hp.top() >= range[i].l){
            hp.push(range[i].r);
        }else{
            hp.pop();
            hp.push(range[i].r);
        }
    }
    
    printf("%d", hp.size());
    
    return 0;
    
}
