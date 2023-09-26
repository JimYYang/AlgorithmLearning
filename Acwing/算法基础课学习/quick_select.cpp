#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];

int quick_select(int l, int r,int k){
    if( l == r)return q[l];
    
    int x = q[(r + l) / 2], i = l - 1, j = r + 1;
    while(i < j){
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j)swap(q[i], q[j]);
    }
    if(k <= j - l + 1)return quick_select(l, j, k);
    return quick_select(j + 1, r, k - (j - l + 1));//不要写else
}
int main(){
    scanf("%d%d", &n, &k);//scanf的&不能掉
    
    for(int i = 0; i < n; ++i)scanf("%d", &q[i]);
    
    cout << quick_select(0, n - 1, k) << endl;
    return 0;
}
