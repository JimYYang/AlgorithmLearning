#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10000010;


// 有线性筛和埃氏筛  常用的是线性筛  线性筛保证每个数只筛一次 不会重复 每个数被自己最小的质因子筛除

// 埃氏筛写法1

// bool isprime[N];

// int n,cnt;
// void  countPrimes(int n){
    
//     for(int i = 2; i <= n / i; i ++){
//         if(!isprime[i]){
//             for(int j = i * i; j <= n; j += i){
//                 isprime[j] = true;
//             }
//         }
//     }
//     for(int i = 2; i <= n; i ++){
//         if(!isprime[i])cnt ++;
//     }
// }

// 埃氏筛写法2

// void get_primes(int n){
//     for(int i = 2; i <= n; i ++){
//         if(!st[i]){
//             primes[cnt ++] = i;
//             for(int j = i + i; j <= n; j += i)st[j] = true;
//         }
//     }
// }



// 线性筛写法
int n;
int cnt, primes[N]; // primes[]存储所有素数
bool st[N];// st[x]存储x是否被筛掉

void get_primes(int n){
    for(int i = 2; i <= n; i ++){
        if(!st[i]) primes[cnt ++] = i;
            for(int j = 0; primes[j] <= n / i; j ++){ // primes[j]是最小的质数
                st[primes[j] * i] = true; // true代表不是质数  这样不需要将st全设为1
                if( i % primes[j] == 0)break;
            }
    }
}




int main(){
    scanf("%d", &n);
    
    get_primes(n);
    printf("%d", cnt);
    return 0;
}
