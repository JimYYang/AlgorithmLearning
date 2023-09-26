// 单峰才可以用贪心处理

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

bool cmp(PII &a, PII &b){
    return a.second < b.second;
}


const int N = 100010;
PII inter[N];

int main(){
    int n;
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &a, &b);
        inter[i] = {a, b};
    }
    
    sort(inter, inter + n, cmp);
    
    int res = 0, end = -2e9;
    
    for(int i = 0; i < n; i ++){
        if(end < inter[i].first){
            res ++;
            end = inter[i].second;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
