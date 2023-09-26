// 注意要求m1  m2 .. mn两两互质

// 这题 m a输入是反的

// 凡是有long  long  double string 等  都改用cin   cout

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

int n;

LL exgcd(LL a, LL b, LL &k1, LL &k2){
    if(!b){
        k1 = 1, k2 = 0;
        return a;
    }
    
    LL d = exgcd(b, a % b, k2, k1);
    k2 -= a / b * k1; //注意这样写可以防止溢出
    return d;
}


int main(){
    scanf("%d", &n);
    
    LL a1, m1;
    // scanf("%d%d", &a1, &m1);
    cin >> m1 >> a1;
    swap(m1, a1);
    bool flag = true;
    while(--n){
        LL a2, m2, k1, k2;
        // scanf("%d%d", &a2, &m2);
        cin >> m2 >> a2;
        swap(m2, a2);
        
        LL d = exgcd(a1, a2, k1, k2);
        if((m2 - m1) % d ){
            flag = false;
            break;
        }
        k1 *= (m2 - m1) / d;
        
        LL t = a2 / d;
        
        k1 = (k1 % t + t) % t; //将k 变得尽可能小
        
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2); // 这样防止溢出 最小公倍数求正的负的都可以
    }
    
    if(flag)
        //printf("%d\n", (m1 % a1 + a1) % a1); // x = ka + m  k是整数  这样求得的x为最小正数
        cout << (m1 % a1 + a1) % a1 << endl;
    else cout << -1 <<endl;
    
    return 0;
}
