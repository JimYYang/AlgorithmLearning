// 先分解质因数 转化为高精度乘法   高精度除高精度  高精度×高精度  再看


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5010;

int primes[N], cnt;
int st[N];
int sum_p[N];


void get_primes(int n){
    for(int i = 2;  i <= n; i ++){
        if(!st[i])primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)break;
        }
    }
}

int get(int n, int p){// 这个就是197题 求n!分解质因数
    int res = 0;
    while(n){
        res += n / p;
        n = n / p;
    }
    return res;
}


vector<int> mul(vector<int> & a, int b){
    vector<int> c;
    int carry = 0;
    for(int i = 0; i < a.size() || carry; i ++){
        if(i < a.size()) carry += a[i] * b;
        
        c.push_back(carry % 10);
        carry /= 10;
    }
    
    if(a.size() > 1 && a.back() == 0)a.pop_back(); //这题不会存在前导0  只有× 0 才会有
    return c;
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    
    get_primes(a);
    
    for(int i = 0; i < cnt; i ++){
        int p = primes[i];
        sum_p[i] = get(a, p) - get(b, p) - get(a - b, p); // 自己举例子算一遍就明白了
    }
    
    vector<int>res(1, 1);
    
    for(int i = 0; i < cnt; i ++){
        for(int j = 0; j < sum_p[i]; j ++)
            res = mul(res, primes[i]);
    }
    
    
    for(int i = res.size() - 1; i >= 0; i --){
        printf("%d", res[i]);
    }
    
    return 0;
}
