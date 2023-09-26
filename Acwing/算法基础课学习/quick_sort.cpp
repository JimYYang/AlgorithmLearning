#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r)return;
    
    int x = q[(l + r ) / 2 ], i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)swap(q[i], q[j]);
    }
    
    //可以写成 l i - 1, i  r  但是注意不能取l  可以取r  或者中间值
    quick_sort(q, l, j);//这样写不能取r  可以取l 或者中间值
    quick_sort(q, j + 1, r);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)scanf("%d", &q[i]);
    //因为q定义为全局的  所以可以直接使用int q[]
    quick_sort(q, 0, n - 1);
    
    for(int i = 0; i < n; ++i)printf("%d ", q[i]);//有一个空格
    
    return 0;
}
