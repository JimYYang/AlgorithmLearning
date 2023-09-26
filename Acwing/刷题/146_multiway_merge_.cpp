// 多路归并
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>


#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 2010;

int T;
int m, n;
int a[N], b[N], c[N];

void merge(){
   priority_queue<PII, vector<PII>, greater<PII>> heap;
   
   for(int i = 0; i < n; i ++)heap.push({a[0] + b[i], 0});
   
   for(int i = 0; i < n; i ++){
      auto cur = heap.top();
      heap.pop();
      int s = cur.x, id = cur.y;
      c[i] = s;
      heap.push({s - a[id] + a[id + 1], id + 1});
   }
   
   for(int i = 0; i < n; i ++)a[i] = c[i];
}

int main(){
    
    scanf("%d", &T);
    
    while(T --){
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; i ++)scanf("%d", &a[i]);
        
        sort(a, a + n);
        
        for(int i = 0; i < m - 1; i ++){
            for(int j = 0; j < n; j ++) scanf("%d", &b[j]);
            merge();
        }
        
        for(int i = 0; i < n; i ++)printf("%d ", a[i]);
        puts("");
    }
    
    return 0;
}
