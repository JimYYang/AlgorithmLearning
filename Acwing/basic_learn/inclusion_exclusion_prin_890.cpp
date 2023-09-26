// 大数据范围  预处理

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 20;

int p[N];

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; i ++)scanf("%d", &p[i]); //注意 读入的质数可能会不在n范围内
    
    int res = 0;
    
    for(int i = 1; i < 1 << m; i ++){
        LL mul = 1;
        int cnt = 0;
        
        for(int j = 0; j < m; j ++){
            if(i >> j & 1){
                cnt ++;
            if(mul * p[j] > n){
                mul = -1;
                break;
                }
            mul *= p[j];
            }
        }
        
        if(mul != -1){
            if(cnt & 1)res += n / mul;
            else res -= n / mul;
        }
    }
    
    printf("%d", res);
    
    return 0;
}
