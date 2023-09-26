#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, m;
int q[N],pre_sum[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &q[i]);
        pre_sum[i] += pre_sum[i-1] + q[i];
    }
    
    //如果是自己处理输入输出一个数组就够了  cin >> a[i]; a[i] += a[i-1];  二维同理  注意当数组下标从0开始时  s[i] 表示0 - i-1 的和 有一个偏移量  所以在原公式上偏移一位即可
    
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        cout << pre_sum[r] - pre_sum[l-1] <<endl;
    }
    return 0;
}
